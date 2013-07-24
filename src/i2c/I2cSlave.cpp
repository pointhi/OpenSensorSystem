/**
 * @file OssI2cSlave.cpp
 *
 * @author thomas
 *
 * @date 17. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#include <iostream>
#include <string>
#include <sstream>
#include <tr1/memory>

#include <tinyxml2.h>

#include "../../include/OssTree.hpp"
#include "../../include/i2c/OssI2cSlave.hpp"

namespace oss {
    namespace i2c {

        /**
         *
         */

        Slave::Slave() : i2cAdress(0) {
        }

        Slave::Slave(std::string newName) : i2cAdress(0) {
            this->SetName(newName);
        }

        Slave::Slave(const Slave& orig) {
        }

        Slave::~Slave() {
        }

        void Slave::parseXml(tinyxml2::XMLNode * const xmlNode) {
            if (std::string(xmlNode->ToElement()->Name()) == std::string("i2c-slave")) {
                this->parseMainXmlParameter(xmlNode);
            } else {
                std::clog << "WARNING: <i2c-slave> isn't parent-node, ignoring child elements and values" << std::endl;
            }
        }

        void Slave::parseMainXmlParameter(tinyxml2::XMLNode * const xmlNode) {
            if (xmlNode->FirstChildElement("name")) {
                this->SetName(xmlNode->FirstChildElement("name")->GetText());
            }
            if (xmlNode->FirstChildElement("adress")) {
                this->SetI2cAdress(xmlNode->FirstChildElement("adress")->GetText());
            }
        }

        void Slave::SetI2cAdress(std::string adress) {
            std::stringstream ss;
            ss << std::hex << adress;
            ss >> this->i2cAdress;
        }

        void Slave::SetI2cAdress(unsigned int adress) {
            this->i2cAdress = adress;
        }

    }
}