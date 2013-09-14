/**
 * @file OssI2cSmbSlave.cpp
 *
 * @author thomas
 *
 * @date 17. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#include <iostream>
#include <string>
#include <tr1/memory>

#include <tinyxml2.h>

#include "../../include/OssTree.hpp"
#include "../../include/i2c/OssI2cSlave.hpp"
#include "../../include/i2c/OssI2cSmbSlave.hpp"

namespace oss {
    namespace i2c {

        SmbSlave::SmbSlave() {
        }

        SmbSlave::SmbSlave(std::string newName) {
            this->SetVariable("name", newName);
        }

        SmbSlave::SmbSlave(const SmbSlave& orig) {
        }

        SmbSlave::~SmbSlave() {
        }

        void SmbSlave::parseXml(tinyxml2::XMLNode * const xmlNode) {
            if (std::string(xmlNode->ToElement()->Name()) == std::string("smb-slave")) {
                this->parseMainXmlParameter(xmlNode);
                this->MainTreeGroup::parseMainXmlParameter(xmlNode);
            } else {
                std::clog << "WARNING: <smb-slave> isn't parent-node, ignoring child elements and values" << std::endl;
            }
        }

    }
}