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

        for (tinyxml2::XMLNode* HelpNode = xmlNode
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
    }

    void RootNode::parseXml(std::string filePath) {
        tinyxml2::XMLDocument doc;
        doc.LoadFile(filePath.c_str());

        this->parseXml(doc.FirstChild());
    }

}