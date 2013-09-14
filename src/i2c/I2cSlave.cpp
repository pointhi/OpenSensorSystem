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
#include "../../include/OssSpecialFunctions.hpp"

namespace oss {
    namespace i2c {

        Slave::Slave() {
        }

        Slave::Slave(std::string newName) {
            this->SetVariable("name", newName);
        }

        Slave::Slave(const Slave& orig) {
        }

        Slave::~Slave() {
        }

        void Slave::parseXml(tinyxml2::XMLNode * const xmlNode) {
            if (std::string(xmlNode->ToElement()->Name()) == std::string("i2c-slave")) {
                this->parseMainXmlParameter(xmlNode);
                this->MainTreeGroup::parseMainXmlParameter(xmlNode);
            } else {
                std::clog << "WARNING: <i2c-slave> isn't parent-node, ignoring child elements and values" << std::endl;
            }
        }

        void Slave::parseMainXmlParameter(tinyxml2::XMLNode * const xmlNode) {
        }

    }
}