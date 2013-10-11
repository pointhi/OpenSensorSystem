/**
 * @file OssRootNode.cpp
 *
 * @author thomas
 *
 * @date 24. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#include <iostream>
#include <string>
#include <tr1/memory>

#include <tinyxml2.h>

#include "../include/OssRootNode.hpp"
#include "../include/OssTree.hpp"
#include "../include/OssGroups.hpp"
#include "../include/i2c/OssI2cHost.hpp"
#include "../include/OssConstants.hpp"

namespace oss {

    RootNode::RootNode() {
        this->SetVariable(oss::constants::variableNames::ObjectName, "ROOT");
    }

    RootNode::RootNode(const RootNode& orig) {
    }

    RootNode::~RootNode() {
    }

    void RootNode::parseXml(tinyxml2::XMLNode * const xmlNode) {

        std::string childName;

        if (xmlNode) {
            for (tinyxml2::XMLElement* helpElement = xmlNode->FirstChildElement()
                    ; helpElement != NULL
                    ; helpElement = helpElement->NextSiblingElement()
                    ) {

                childName.clear();
                childName = helpElement->ToElement()->Name();

                if (childName == oss::constants::xmlElementNames::hostElements::Io) {
                } else if (childName == oss::constants::xmlElementNames::hostElements::I2c) {
                    std::tr1::shared_ptr<oss::HostGroup> newChildElement(new oss::i2c::Host);
                    this->AddChildNode(newChildElement);
                    newChildElement->parseXml(helpElement);
                } else if (childName == oss::constants::xmlElementNames::hostElements::Can) {
                } else if (childName == oss::constants::xmlElementNames::hostElements::Spi) {
                } else if (childName == oss::constants::xmlElementNames::hostElements::Uart) {
                } else if (childName == oss::constants::xmlElementNames::hostElements::Ethernet) {
                }
            }

            this->MainTreeGroup::parseMainXmlParameter(xmlNode);
        } else {
            std::cerr << "ERROR: Node doesn't contain a <root> element!" << std::endl;
        }
    }

    void RootNode::parseXml(std::string filePath) {
        tinyxml2::XMLDocument doc;

        switch (doc.LoadFile(filePath.c_str())) {
            case tinyxml2::XML_NO_ERROR:
                if (doc.FirstChildElement(oss::constants::xmlElementNames::RootElementName.c_str())) {
                    for (tinyxml2::XMLElement* helpElement = doc.FirstChildElement(oss::constants::xmlElementNames::RootElementName.c_str())
                            ; helpElement != NULL
                            ; helpElement = helpElement->NextSiblingElement(oss::constants::xmlElementNames::RootElementName.c_str())
                            ) {
                        this->parseXml(helpElement);
                    }
                } else {
                    std::cerr << "ERROR: XML-File doesn't contain a <root> element!" << std::endl;
                }
                break;
            case tinyxml2::XML_ERROR_FILE_NOT_FOUND:
                std::cerr << "ERROR: File: \"" << filePath << "\" doesn't found" << std::endl;
                break;
            case tinyxml2::XML_ERROR_FILE_COULD_NOT_BE_OPENED:
                std::cerr << "ERROR: File: \"" << filePath << "\" could not be open" << std::endl;
                break;
            case tinyxml2::XML_ERROR_EMPTY_DOCUMENT:
                std::cerr << "ERROR: File: \"" << filePath << "\" doesn't contain data" << std::endl;
                break;
            default:
                std::cerr << "ERROR: File: \"" << filePath << "\" throw unknow error" << std::endl;
                break;
        }
    }

    oss::sensor::SensorGroup * const RootNode::GetSensor(const std::string name) const {
        for (std::set<oss::sensor::SensorGroup*>::iterator it = this->sensorListOld.begin()
                ; it != this->sensorListOld.end()
                ; it++
                ) {

            if ((*it)->GetVariable(oss::constants::variableNames::ObjectName) == name) {
                return *it;
            }
        }
        throw "No Sensor Element found";
    }

    oss::sensor::SensorGroup * const RootNode::GetSensor(const unsigned int id) const {
        if (id<this->sensorListOld.size()) {
            std::set<oss::sensor::SensorGroup*>::iterator it = this->sensorListOld.begin();

            for (unsigned int i = 0; i < id; it++, i++);

            return *it;
        }
        throw "Id to high";
    }

}