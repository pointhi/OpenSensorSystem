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

namespace oss {
    namespace lua {

        LuaSensorScript::LuaSensorScript() {
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
            if (luaL_dofile(this->LuaState, this->GetVariable("file").c_str())) {
                std::clog << "WARNING: " << lua_tostring(this->LuaState, -1) << std::endl;
            }

            // Loading main functions
            luabind::module(this->LuaState) [
                    luabind::class_<LuaSensorScript>("oss")
                    .def("GetVariable", &oss::tree::TreeNode::GetVariable)
                    .def("SetVariable", &oss::tree::TreeNode::SetVariable)
                    .def("GetConstante", &oss::tree::TreeNode::GetConstante)
                    //.def("GetChildNode", &oss::tree::TreeNode::GetChildNode)
                    //.def("AddChildNode", &oss::tree::TreeNode::AddChildNode)
                    //.def("GetParrentNode", &oss::tree::TreeNode::GetParrentNode)
                    //.def("GetRootNode", &oss::tree::TreeNode::GetRootNode)
                    ];

            // Bind to this object

            luabind::globals(this->LuaState)["oss"] = this;

            try {
                // Call Init Function
                luabind::call_function<void>(this->LuaState, "init");
            } catch (luabind::error e) {
                std::cerr << "ERROR: " << e.what() << ", " << luabind::object(luabind::from_stack(e.state(), -1)) << std::endl;
            }
        }

        void LuaSensorScript::RunNode() {

            try {
                // Call Init Function
                luabind::call_function<void>(this->LuaState, "run");
            } catch (luabind::error e) {
                std::cerr << "ERROR: " << e.what() << ", " << luabind::object(luabind::from_stack(e.state(), -1)) << std::endl;
            }

            this->TreeNode::RunNode();
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