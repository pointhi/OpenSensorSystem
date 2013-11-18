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
#include <set>

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

#ifdef DEBUG
        std::clog << "DEBUG: Parse XML-File: " << filePath << std::endl;
#endif

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

    std::tr1::shared_ptr<oss::sensor::SensorGroup> RootNode::GetSensor(const std::string _name) const {
        for (std::set<std::tr1::weak_ptr<oss::sensor::SensorGroup> >::iterator it = this->sensorList.begin()
                ; it != this->sensorList.end()
                ; it++
                ) {

            if ((*it).lock()->GetVariable(oss::constants::variableNames::ObjectName) == _name) {
                return (*it).lock();
            }
        }
#ifdef DEBUG
        std::clog << "DEBUG: RootNode::GetSensor(" << _name << "), element not found" << std::endl;
#endif
        throw "No Sensor Element found";
    }

    std::tr1::shared_ptr<oss::sensor::SensorGroup> RootNode::GetSensor(const unsigned int _id) const {
        if (_id < this->sensorList.size()) {
            std::set<std::tr1::weak_ptr<oss::sensor::SensorGroup> >::iterator it = this->sensorList.begin();

            for (unsigned int i = 0; i < _id; it++, i++);

            return (*it).lock();
        }
#ifdef DEBUG
        std::clog << "DEBUG: RootNode::GetSensor(" << _id << "), element not found (Id to high)" << std::endl;
#endif
        throw "Id to high";
    }

    unsigned int RootNode::GetSensorSize() {
        for (std::set<std::tr1::weak_ptr<oss::sensor::SensorGroup> >::iterator it = this->sensorList.begin()
                ; it != this->sensorList.end()
                ; it++
                ) {

            if ((*it).expired()) {
                std::tr1::weak_ptr<oss::sensor::SensorGroup> remove(it->lock());
                this->sensorList.erase(it);
                it = this->sensorList.begin();
            }
        }
        return this->sensorList.size();
    }

}