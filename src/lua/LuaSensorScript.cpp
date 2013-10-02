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

#include "../../include/lua/OssLuaSensorScript.hpp"
#include "../../include/OssGroups.hpp"
#include "../../include/OssConstants.hpp"
#include "../../include/sensor/OssSensor.hpp"

namespace oss {
    namespace lua {

        LuaSensorScript::LuaSensorScript() {
        }

        LuaSensorScript::LuaSensorScript(const LuaSensorScript& orig) {
        }

        LuaSensorScript::~LuaSensorScript() {
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