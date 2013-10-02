/**
 * @file OssI2cHost.cpp
 *
 * @author thomas
 *
 * @date 1. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#include <iostream>
#include <string>
#include <sstream>
#include <locale>
#include <tr1/memory>

#include <tinyxml2.h>

#include "../../include/OssTree.hpp"
#include "../../include/OssGroups.hpp"
#include "../../include/i2c/OssI2cHost.hpp"
#include "../../include/i2c/OssI2cSlave.hpp"
#include "../../include/i2c/OssI2cSmbSlave.hpp"
#include "../../include/OssSpecialFunctions.hpp"
#include "../../include/OssConstants.hpp"

namespace oss {
    namespace i2c {

        Host::Host() {
        }

        Host::Host(std::string newName) {
            this->SetVariable(oss::constants::variableNames::ObjectName, newName);
        }

        Host::Host(const Host& orig) {
        }

        Host::~Host() {
        }

        void Host::parseXml(tinyxml2::XMLNode * const xmlNode) {

            // Check if node is in correct DOM-Namespace
            if (std::string(xmlNode->ToElement()->Name()) == oss::constants::xmlElementNames::hostElements::I2c) {

                std::string childName;

                for (tinyxml2::XMLElement* helpElement = xmlNode->FirstChildElement()
                        ; helpElement != NULL
                        ; helpElement = helpElement->NextSiblingElement()
                        ) {

                    childName.clear();
                    childName = helpElement->Name();

                    if (childName == oss::constants::xmlElementNames::i2cElements::I2cSlave) {
                        std::tr1::shared_ptr<oss::i2c::I2cGroup> newChildElement(new oss::i2c::Slave);
                        this->AddChildNode(newChildElement);
                        newChildElement->parseXml(helpElement);
                    } else if (childName == oss::constants::xmlElementNames::i2cElements::SmbSlave) {
                        std::tr1::shared_ptr<oss::i2c::I2cGroup> newChildElement(new oss::i2c::SmbSlave);
                        this->AddChildNode(newChildElement);
                        newChildElement->parseXml(helpElement);
                    }
                }

                this->MainTreeGroup::parseMainXmlParameter(xmlNode);
            } else {
                std::clog << "WARNING: <" << oss::constants::xmlElementNames::hostElements::I2c << "> isn't parent-node, ignoring child elements and values, node is: <" << std::string(xmlNode->ToElement()->Name()) << ">" << std::endl;
            }
        }

    }
}