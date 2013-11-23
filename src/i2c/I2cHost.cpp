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
#include <stdexcept>
#include <vector>

#ifdef __linux__
// Loading I2C-Linux-Drivers
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#else
#warning No Linux enviroment, i2c is disabled!
#endif

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

        Host::Host() : i2cHandler(-1) {
#ifdef __linux__

#else
            std::clog << "WARNING: oss::I2cHost, I2C doesn't work on this System" << std::endl;
#endif
        }

        Host::Host(std::string newName) {
            this->SetVariable(oss::constants::variableNames::ObjectName, newName);
        }

        Host::Host(const Host& orig) {
        }

        Host::~Host() {
#ifdef __linux__
            if (this->i2cHandler != -1 && close(this->i2cHandler) != 0) {
                std::cerr << "ERROR: oss::I2cHost, Failed to close stream" << std::endl;
            }
#endif
        }

        void Host::parseXml(tinyxml2::XMLNode * const xmlNode) {

            // Check if node is in correct DOM-Namespace
            if (std::string(xmlNode->ToElement()->Name()) == oss::constants::xmlElementNames::hostElements::I2c) {

                this->MainTreeGroup::parseMainXmlParameter(xmlNode);
                this->InitI2C();

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
            } else {
                std::clog << "WARNING: <" << oss::constants::xmlElementNames::hostElements::I2c << "> isn't parent-node, ignoring child elements and values, node is: <" << std::string(xmlNode->ToElement()->Name()) << ">" << std::endl;
            }
        }

        void Host::InitI2C() {
            if (!this->GetVariable(oss::constants::variableNames::DevicePath).empty()) {

#ifdef __linux__

                // Open Device
#ifdef DEBUG
                std::clog << "DEBUG: Open Device: \"" << this->GetVariable(oss::constants::variableNames::DevicePath) << "\"" << std::endl;
#endif
                if ((this->i2cHandler = open(this->GetVariable(oss::constants::variableNames::DevicePath).c_str(), O_RDWR)) < 0) {
                    std::cerr << "ERROR: oss::I2cHost, Failed to open stream: \"" << this->GetVariable(oss::constants::variableNames::DevicePath) << "\"" << std::endl;
                }
#endif

            } else {
                std::clog << "WARNING: oss::I2cHost, No device path specified" << std::endl;
            }
        }

        void Host::I2cSetAdress(const unsigned int i2cAdress) {
#ifdef __linux__
            if (this->i2cHandler != -1) {

                int result = ioctl(this->i2cHandler, I2C_SLAVE, i2cAdress);
                if (result == -1) {
                    throw std::runtime_error("Unable to get bus access to talk to slave");
                }
            }
#endif
        }

        void Host::I2cWrite(const unsigned int i2cAdress, const std::vector<unsigned char> data) {
            if (this->i2cHandler != -1 && !data.empty()) {
                this->I2cSetAdress(i2cAdress);

#ifdef __linux__
                if (write(this->i2cHandler, &data[0], data.size()) != data.size()) {
                    throw std::runtime_error("Failed to write to I2c-Slave");
                }
#endif
            }
        }

        const std::vector<unsigned char> Host::I2cRead(const unsigned int i2cAdress, const unsigned int dataLenght) {
            if (this->i2cHandler != -1 && dataLenght) {
                this->I2cSetAdress(i2cAdress);

#ifdef __linux__
                std::vector<unsigned char> returnVector(dataLenght);
                if (write(this->i2cHandler, &returnVector[0], dataLenght) != dataLenght) {
                    throw std::runtime_error("Failed to read from I2c-Slave");
                }
                return returnVector;
#endif
            }
            return std::vector<unsigned char>(0);
        }

    }
}