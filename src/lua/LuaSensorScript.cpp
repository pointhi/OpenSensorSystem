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
#include <lua5.2/lua.h>
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
        }

        LuaSensorScript::LuaSensorScript(const LuaSensorScript& orig) {
        }

        LuaSensorScript::~LuaSensorScript() {
            // Close a new lua state
            //             lua_close(this->LuaState);
        }

        void LuaSensorScript::InitChild() {
            this->InitLua();
        }

        void LuaSensorScript::InitLua() {
            //            luabind::module(this->LuaState) [
            //                    luabind::def("oss::GetVariable", &oss::tree::TreeNode::GetVariable)
            //                    ];
        }

        void LuaSensorScript::RunNode() {

            //            luaL_dostring(this->LuaState, "return 'derp'");

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
            } else {
                std::clog << "WARNING: <" << oss::constants::xmlElementNames::luaElements::LuaScript << "> isn't parent-node, ignoring child elements and values, node is: <" << std::string(xmlNode->ToElement()->Name()) << ">" << std::endl;
            }
        }

    }
}