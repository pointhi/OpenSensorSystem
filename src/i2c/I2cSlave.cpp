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
#include <vector>

#include <tinyxml2.h>
#include <luabind/class.hpp>
#include <luabind/iterator_policy.hpp>

#include "../../include/OssTree.hpp"
#include "../../include/i2c/OssI2cSlave.hpp"
#include "../../include/OssSpecialFunctions.hpp"
#include "../../include/OssConstants.hpp"

#include "../../include/sensor/OssSensor.hpp"
#include "../../include/lua/OssLuaSensorScript.hpp"

namespace oss {
    namespace i2c {

        Slave::Slave() {
        }

        Slave::Slave(std::string newName) {
            this->SetVariable(oss::constants::variableNames::ObjectName, newName);
        }

        Slave::Slave(const Slave& orig) {
        }

        Slave::~Slave() {
        }

        void Slave::parseXml(tinyxml2::XMLNode * const xmlNode) {
            if (std::string(xmlNode->ToElement()->Name()) == oss::constants::xmlElementNames::i2cElements::I2cSlave) {

                std::string childName;

                for (tinyxml2::XMLElement* helpElement = xmlNode->FirstChildElement()
                        ; helpElement != NULL
                        ; helpElement = helpElement->NextSiblingElement()
                        ) {

                    childName.clear();
                    childName = helpElement->Name();

                    if (childName == oss::constants::xmlElementNames::luaElements::LuaScript) {
                        std::tr1::shared_ptr<oss::lua::LuaGroup> newChildElement(new oss::lua::LuaSensorScript);
                        this->AddChildNode(newChildElement);
                        newChildElement->parseXml(helpElement);
                    }
                }

                this->parseMainXmlParameter(xmlNode);
                this->MainTreeGroup::parseMainXmlParameter(xmlNode);
            } else {
                std::clog << "WARNING: <" << oss::constants::xmlElementNames::i2cElements::I2cSlave << "> isn't parent-node, ignoring child elements and values, node is: <" << std::string(xmlNode->ToElement()->Name()) << ">" << std::endl;
            }
        }

        void Slave::parseMainXmlParameter(tinyxml2::XMLNode * const xmlNode) {
        }

        void Slave::RegisterInLua(luabind::class_<Slave>& x) {
            x.def("readFromSlave", &oss::i2c::Slave::readFromSlave, luabind::return_stl_iterator);
            x.def("writeToSlave", &oss::i2c::Slave::writeToSlave);
        }

        std::vector<unsigned char> Slave::readFromSlave(unsigned int _bits) {
            std::vector<unsigned char> helpvector;
            //            helpvector.push_back((unsigned char) 10);
            //            helpvector.push_back((unsigned char) 20);
            //            helpvector.push_back((unsigned char) 30);
            //            helpvector.push_back((unsigned char) 40);
            return helpvector;
        }

        void Slave::writeToSlave(std::vector<unsigned char> _writeData) {
        }

    }
}