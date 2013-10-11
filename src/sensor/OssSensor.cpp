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
            std::cout << "WARNING: Please use konstructor, with set the parrent node automaticly" << std::endl;
        }

        Sensor::Sensor(const std::tr1::shared_ptr<oss::tree::TreeNode> parentNode) {
            this->SetParrentNode(parentNode);

            //            std::tr1::shared_ptr<oss::RootNode> rootNode(dynamic_cast<std::tr1::shared_ptr<oss::RootNode> > (this->GetRootNode()));
            //            if (rootNode) {   // TODO
            //                rootNode->AddSensor(this);
            //            }
        }

        Sensor::Sensor(const Sensor& orig) {

        }

        Sensor::~Sensor() {
            //            oss::RootNode *rootNode = dynamic_cast<oss::RootNode*> (const_cast<TreeNode*> (this->GetRootNode()));
            //            //            std::cout << "remove " << this->GetRootNode()->GetVariable("name") << std::endl;
            //            if (rootNode) {
            //                rootNode->RemoveSensor(this);
            //            }
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
