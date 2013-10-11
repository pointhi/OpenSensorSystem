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
            // Old code, openpoint todo
            //            std::tr1::shared_ptr<oss::RootNode> rootNode(dynamic_cast<std::tr1::shared_ptr<oss::RootNode> > (this->GetRootNode()));
            //            if (rootNode) {
            //                rootNode->AddSensor(this);
            //            }
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
