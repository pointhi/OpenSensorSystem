/**
 * @file OssGroups.cpp
 *
 * @author thomas
 *
 * @date 24. August 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#include "../include/OssGroups.hpp"
#include "../include/OssTree.hpp"

#include <tinyxml2.h>
#include <iostream>

namespace oss {

    MainTreeGroup::~MainTreeGroup() {
    }

    void MainTreeGroup::parseMainXmlParameter(tinyxml2::XMLNode * const xmlNode) {
        if (xmlNode->ToElement()->Attribute("status") == "enabled") {
            this->SetState(oss::NodeState::WAITING);
        } else if (xmlNode->ToElement()->Attribute("status") == "disabled") {
            this->SetState(oss::NodeState::DISABLE);
        }

        this->parseVariablesFromXml(xmlNode);
        this->parseConstantsFromXml(xmlNode);
    }

    void MainTreeGroup::parseVariablesFromXml(tinyxml2::XMLNode * const xmlNode) {
        for (const tinyxml2::XMLAttribute *xmlHelpAttribut = xmlNode->ToElement()->FirstAttribute()
                ; xmlHelpAttribut != NULL
                ; xmlHelpAttribut = xmlHelpAttribut->Next()
                ) {
            this->SetVariable(xmlHelpAttribut->Name(), xmlHelpAttribut->Value());
            //            std::cout << "DEBUG: SetVariable: " << xmlAttribut->Name() << " = " << xmlAttribut->Value() << std::endl;
        }
    }

    void MainTreeGroup::parseConstantsFromXml(tinyxml2::XMLNode * const xmlNode) {
        for (const tinyxml2::XMLElement* xmlMainHelpElement = xmlNode->FirstChildElement("define")
                ; xmlMainHelpElement != NULL
                ; xmlMainHelpElement = xmlMainHelpElement->NextSiblingElement("define")
                ) {
            for (const tinyxml2::XMLElement* xmlHelpElement = xmlMainHelpElement->FirstChildElement()
                    ; xmlHelpElement != NULL
                    ; xmlHelpElement = xmlHelpElement->NextSiblingElement()
                    ) {
                if (xmlHelpElement->FindAttribute("value")) {
                    this->SetConstante(xmlHelpElement->Name(), xmlHelpElement->FindAttribute("value")->Value());
                    //                    std::cout << "DEBUG: SetConstant: " << xmlHelpNode->Name() << " = " << xmlHelpNode->FindAttribute("value")->Value() << std::endl;
                } else {
                    std::cout << "WARNING: The Constant: \"" << xmlHelpElement->Name() << "\" doesn't have a value" << std::endl;
                }
            }
        }
    }

    HostGroup::~HostGroup() {
    }

    namespace io {

        IoGroup::~IoGroup() {
        }
    }

    namespace i2c {

        I2cGroup::~I2cGroup() {
        }
    }

    namespace can {

        CanGroup::~CanGroup() {
        }
    }

    namespace spi {

        SpiGroup::~SpiGroup() {
        }
    }

    namespace uart {

        UartGroup::~UartGroup() {
        }
    }

    namespace ethernet {

        EthernetGroup::~EthernetGroup() {
        }
    }

    namespace lua {

        LuaGroup::~LuaGroup() {
        }

        LuaSensorScriptGroup::~LuaSensorScriptGroup() {
        }
    }

    namespace sensor {

        SensorGroup::~SensorGroup() {
        }
    }
}