/**
 * @file OssSensor.cpp
 * @author thomas
 *
 * @date 20. September 2013
 * @copyright GNU General Public License (GPL) 3.0
 *
 * @todo check const_cast<> in constructer and destructor functions
 */

#include <iostream>

#include <tinyxml2.h>

#include "../../include/sensor/OssSensor.hpp"
#include "../../include/OssGroups.hpp"
#include "../../include/OssConstants.hpp"

#include "../../include/OssRootNode.hpp"

namespace oss {

    namespace sensor {

        Sensor::Sensor() {
        }

        void Sensor::InitChild() {

            // Copy Element to Root-Node into help-array
            std::tr1::shared_ptr<oss::RootNode> rootNode = std::tr1::dynamic_pointer_cast<oss::RootNode>(this->GetRootNode());
            // If root-element is correct, then copy a shared_ptr into the dynamic array
            if (rootNode.get()) {
                rootNode->AddSensor(std::tr1::dynamic_pointer_cast<oss::sensor::SensorGroup>(this->GetElementNode()));
            }
        }

        Sensor::Sensor(const Sensor& orig) {

        }

        Sensor::~Sensor() {

        }

        void Sensor::parseXml(tinyxml2::XMLNode * const xmlNode) {
            if (std::string(xmlNode->ToElement()->Name()) == oss::constants::xmlElementNames::sensorElements::GeneralSensor) {
                this->MainTreeGroup::parseMainXmlParameter(xmlNode);
            } else {
                std::clog << "WARNING: <" << oss::constants::xmlElementNames::sensorElements::GeneralSensor << "> isn't parent-node, ignoring child elements and values, node is: <" << std::string(xmlNode->ToElement()->Name()) << ">" << std::endl;
            }
        }
    }
}
