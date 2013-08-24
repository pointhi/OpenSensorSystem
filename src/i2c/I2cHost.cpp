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

namespace oss {
    namespace i2c {

        Host::Host() {
        }

        Host::Host(const Host& orig) {
        }

        Host::~Host() {
        }

        void Host::parseXml(tinyxml2::XMLNode * const xmlNode) {

            // Check if node is in correct DOM-Namespace
            if (std::string(xmlNode->ToElement()->Name()) == std::string("i2c")) {

                if (xmlNode->ToElement()->Attribute("name")) {
                    this->SetName(xmlNode->ToElement()->Attribute("name"));
                }
                if (xmlNode->ToElement()->Attribute("device")) {
                    this->SetDevicePath(xmlNode->ToElement()->Attribute("device"));
                }
                if (xmlNode->ToElement()->Attribute("clock")) {
                    this->SetClockSpeed(xmlNode->ToElement()->Attribute("clock"));
                }

                std::string childName;

                for (tinyxml2::XMLNode* HelpNode = xmlNode->FirstChild()
                        ; HelpNode != NULL
                        ; HelpNode = HelpNode->NextSibling()
                        ) {

                    childName.clear();
                    childName = HelpNode->ToElement()->Name();

                    if (childName == "i2c-slave") {
                        std::tr1::shared_ptr<oss::i2c::I2cGroup> newChildElement(new oss::i2c::Slave);
                        this->AddChildNode(newChildElement);
                        newChildElement->parseXml(HelpNode);
                    } else if (childName == "smb-slave") {
                        std::tr1::shared_ptr<oss::i2c::I2cGroup> newChildElement(new oss::i2c::SmbSlave);
                        this->AddChildNode(newChildElement);
                        newChildElement->parseXml(HelpNode);
                    }
                }

                this->MainTreeGroup::parseMainXmlParameter(xmlNode);
            } else {
                std::clog << "WARNING: <i2c> isn't parent-node, ignoring child elements and values" << std::endl;
            }
        }

        void Host::SetDevicePath(std::string path) {
            this->devicePath = path;
        }

        void Host::SetClockSpeed(std::string clock) {

            //            int i = 0;
            //            for (i = 0; (isdigit(clock.at(i)) || ispunct(clock.at(i))) && i < clock.length(); i++);
            //
            //            std::string suffix = clock.substr(i, clock.length() - i);
            //
            //            std::stringstream ss;
            //            ss << std::hex << clock.substr(0, i);
            //            double helpClock = 0;
            //            ss >> helpClock;
            //
            //            if (suffix == "Hz" || suffix == "") {
            //                this->clockSpeed = helpClock;
            //            } else if (suffix == "kHz") {
            //                this->clockSpeed = helpClock * 1e3;
            //            } else if (suffix == "MHz") {
            //                this->clockSpeed = helpClock * 1e6;
            //            } else if (suffix == "GHz") {
            //                this->clockSpeed = helpClock * 1e9;
            //            }
            this->clockSpeed = oss::specialFunctions::io::GetClockSpeedFromString(clock);
        }

        void Host::SetClockSpeed(double clock) {
            if (clock >= 0) {
                this->clockSpeed = clock;
            } else {
                std::clog << "WARNING: " << clock << "can't be the speed of the bus system" << std::endl;
            }
        }

    }
}