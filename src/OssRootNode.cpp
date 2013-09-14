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

namespace oss {

    RootNode::RootNode() {
        this->SetName("ROOT");
    }

    RootNode::RootNode(const RootNode& orig) {
    }

    RootNode::~RootNode() {
    }

    void RootNode::parseXml(tinyxml2::XMLNode * const xmlNode) {

        std::string childName;

        if (xmlNode) {

            for (tinyxml2::XMLNode* HelpNode = xmlNode->ToElement()->FirstChild()
                    ; HelpNode != NULL
                    ; HelpNode = HelpNode->NextSibling()
                    ) {

                childName.clear();
                childName = HelpNode->ToElement()->Name();

                if (childName == "io") {
                } else if (childName == "i2c") {
                    std::tr1::shared_ptr<oss::HostGroup> newChildElement(new oss::i2c::Host);
                    this->AddChildNode(newChildElement);
                    newChildElement->parseXml(HelpNode);
                } else if (childName == "can") {
                } else if (childName == "spi") {
                } else if (childName == "uart") {
                } else if (childName == "ethernet") {
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
                tinyxml2::XMLNode* HelpNode = doc.FirstChildElement("root");
                if (HelpNode) {
                    for (
                            ; HelpNode != NULL
                            ; HelpNode = HelpNode->NextSibling()
                            ) {
                        this->parseXml(HelpNode);
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

}