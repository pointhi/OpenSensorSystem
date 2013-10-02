/*
 * File:   OssSensor.cpp
 * Author: thomas
 *
 * Created on 20. September 2013, 14:12
 */

#include <iostream>

#include <tinyxml2.h>

#include "../../include/sensor/OssSensor.hpp"
#include "../../include/OssGroups.hpp"
#include "../../include/OssConstants.hpp"

namespace oss {
    namespace sensor {

        Sensor::Sensor() {
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
