/**
 * @file OssLuaSensorScript.cpp
 *
 * @author thomas
 *
 * @date 19. September 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#include <iostream>
#include <string>
#include <sstream>
#include <tr1/memory>

#include <tinyxml2.h>
extern "C" {
#include <lua5.2/lua.h>
#include <lua5.2/lualib.h>
#include <lua5.2/lauxlib.h>
}
#include <luabind/luabind.hpp>

#include "../../include/lua/OssLuaSensorScript.hpp"
#include "../../include/OssGroups.hpp"
#include "../../include/OssConstants.hpp"
#include "../../include/sensor/OssSensor.hpp"
#include "../../include/OssTree.hpp"
#include "../../include/OssNodeType.hpp"

namespace oss {
    namespace lua {

        LuaSensorScript::LuaSensorScript() {
            this->LuaScriptEnabled = false;

            // Create a new lua state
            this->LuaState = luaL_newstate();
            luabind::open(this->LuaState);

            luaL_openlibs(this->LuaState);
        }

        LuaSensorScript::LuaSensorScript(const LuaSensorScript& orig) {
        }

        LuaSensorScript::~LuaSensorScript() {
            // Close a new lua state
            lua_close(this->LuaState);
        }

        void LuaSensorScript::InitChild() {
            // Function is now called from parseXml
            //            this->InitLua();
        }

        void LuaSensorScript::InitLua() {
            // Loading file

#ifdef DEBUG
            std::clog << "DEBUG: Loading Lua-File: " << this->GetVariable(oss::constants::variableNames::FileName) << std::endl;
#endif
            if (luaL_dofile(this->LuaState, this->GetVariable(oss::constants::variableNames::FileName).c_str())) {
                std::clog << "WARNING: " << lua_tostring(this->LuaState, -1) << std::endl;
            }

            // Loading main functions
            luabind::class_<LuaSensorScript> LuaObject_LuaSensorScript("oss");
            this->RegisterInLua(LuaObject_LuaSensorScript);
            luabind::module(this->LuaState) [ LuaObject_LuaSensorScript ];

            // Bind to this object
            luabind::globals(this->LuaState)["oss"] = this;

            // Add List of possible objects
            // example: NodeTypes.oss_i2c_Host
            luabind::class_<oss::NodeType> LuaObject_NodeType("NodeTypes");
            oss::NodeType::RegisterInLua(LuaObject_NodeType);
            luabind::module(this->LuaState) [ LuaObject_NodeType ];

            try {
                // Call Init Function
                if (luabind::call_function<bool>(this->LuaState, "check")) {
                    this->LuaScriptEnabled = true;
                    // Init Class
                    luabind::call_function<void>(this->LuaState, "init");
                } else {
                    this->LuaScriptEnabled = false;
                    std::cerr << "ERROR: Lua Script is not compatible, file: " << this->GetVariable(oss::constants::variableNames::FileName) << std::endl;
                }
            } catch (luabind::error e) {
                std::cerr << "ERROR: " << e.what() << ", " << luabind::object(luabind::from_stack(e.state(), -1)) << std::endl;
            }
        }

        void LuaSensorScript::RegisterInLua(luabind::class_<LuaSensorScript>& x) {
            x.def("GetVariable", &oss::tree::TreeNode::GetVariable);
            x.def("SetVariable", &oss::tree::TreeNode::SetVariable);
            x.def("GetConstante", &oss::tree::TreeNode::GetConstante);
            x.def("SetConstante", &oss::tree::TreeNode::SetConstante);
            x.def("GetVariableFromParrent", &oss::lua::LuaSensorScript::GetVariableFromParrent);
            x.def("GetNodeTypeFromParrent", &oss::lua::LuaSensorScript::GetNodeTypeFromParrent);

            x.def("GetVariableFromChildNode", (const std::string(oss::lua::LuaSensorScript::*)(std::string, const std::string)) & oss::lua::LuaSensorScript::GetVariableFromChildNode);
            x.def("GetVariableFromChildNode", (const std::string(oss::lua::LuaSensorScript::*)(std::string, const unsigned int)) & oss::lua::LuaSensorScript::GetVariableFromChildNode);
            x.def("GetNodeTypeFromChildNode", (const oss::NodeType::NodeTypes(oss::lua::LuaSensorScript::*)(const std::string)) & oss::lua::LuaSensorScript::GetNodeTypeFromChildNode);
            x.def("GetNodeTypeFromChildNode", (const oss::NodeType::NodeTypes(oss::lua::LuaSensorScript::*)(const unsigned int)) & oss::lua::LuaSensorScript::GetNodeTypeFromChildNode);

            //x.def("GetChildNode", (std::tr1::shared_ptr<oss::tree::TreeNode>(oss::tree::TreeNode::*)(const unsigned int)) & oss::tree::TreeNode::GetChildNode);
            //x.def("GetChildNode", (std::tr1::shared_ptr<oss::tree::TreeNode>(oss::tree::TreeNode::*)(const std::string)) & oss::tree::TreeNode::GetChildNode);
            x.def("GetChildSize", &oss::tree::TreeNode::GetChildSize);
            //x.def("GetParrentNode", &oss::tree::TreeNode::GetParrentNode);
            //x.def("GetRootNode", &oss::tree::TreeNode::GetRootNode);
        }

        void LuaSensorScript::RunNode() {
            if (this->LuaScriptEnabled) {
                try {
                    // Call Init Function
                    luabind::call_function<void>(this->LuaState, "run");
                } catch (luabind::error e) {
                    std::cerr << "ERROR: " << e.what() << ", " << luabind::object(luabind::from_stack(e.state(), -1)) << std::endl;
                }

                this->TreeNode::RunNode();
            }
        }

        void LuaSensorScript::parseXml(tinyxml2::XMLNode * const xmlNode) {
            if (std::string(xmlNode->ToElement()->Name()) == oss::constants::xmlElementNames::luaElements::LuaScript) {

                std::string childName;

                for (tinyxml2::XMLElement* helpElement = xmlNode->FirstChildElement()
                        ; helpElement != NULL
                        ; helpElement = helpElement->NextSiblingElement()
                        ) {

                    childName.clear();
                    childName = helpElement->Name();

                    if (childName == oss::constants::xmlElementNames::luaElements::LuaScript) {
                        std::tr1::shared_ptr<oss::helpGroups::LuaAndSensorGroup> newChildElement(new oss::lua::LuaSensorScript);
                        this->AddChildNode(newChildElement);
                        newChildElement->parseXml(helpElement);
                    } else if (childName == oss::constants::xmlElementNames::sensorElements::GeneralSensor) {
                        std::tr1::shared_ptr<oss::helpGroups::LuaAndSensorGroup> newChildElement(new oss::sensor::Sensor);
                        this->AddChildNode(newChildElement);
                        newChildElement->parseXml(helpElement);
                    }
                }

                this->MainTreeGroup::parseMainXmlParameter(xmlNode);
                this->InitLua();
            } else {
                std::clog << "WARNING: <" << oss::constants::xmlElementNames::luaElements::LuaScript << "> isn't parent-node, ignoring child elements and values, node is: <" << std::string(xmlNode->ToElement()->Name()) << ">" << std::endl;
            }
        }

    }
}