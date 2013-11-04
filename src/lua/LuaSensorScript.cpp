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
            //            luabind::module(this->LuaState) [
            //                    //                    luabind::def("GetVariable", &oss::tree::TreeNode::GetVariable),
            //                    luabind::def("RunNode", &oss::lua::LuaSensorScript::RunNode)
            //                    ];

            //            luaL_dostring(
            //                    this->LuaState,
            //                    "function init()\n"
            //                    "  print(\"Hello Lua init\")"
            //                    "end\n"
            //                    );

            luaL_dofile(this->LuaState, this->GetVariable("file").c_str());


            // Loading Constants
            //            luabind::module(this->LuaState)
            //                    [
            //                    luabind::namespace_("oss")
            //                    [
            //                    luabind::namespace_("constants")
            //                    [
            //                    luabind::namespace_("variableNames")
            //                    [
            //                    //                    luabind::value("ObjectName", &oss::constants::variableNames::ObjectName)
            //                    luabind::namespace_("variousVariables")
            //                    [
            //                    ]
            //                    ]
            //                    ]
            //                    ]
            //                    ];

            try {
                // Call Init Function
                luabind::call_function<void>(this->LuaState, "init");
            } catch (luabind::error e) {
                std::cerr << e.what() << std::endl;
            }
        }

        void LuaSensorScript::RunNode() {

            //            luaL_dostring(this->LuaState, "print(\"test: \", 1)");
            std::cout << "run node: " << this->GetVariable("file") << std::endl;

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