/**
 * @file OssGroups.cpp
 *
 * @author thomas
 *
 * @date 24. August 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#include "../include/OssGroups.hpp"

#include <tinyxml2.h>

namespace oss {

    MainTreeGroup::~MainTreeGroup() {
    }

    void MainTreeGroup::parseMainXmlParameter(tinyxml2::XMLNode * const xmlNode) {
        if (xmlNode->ToElement()->Attribute("status") == "enabled") {
            this->SetState(oss::NodeState::WAITING);
        } else if (xmlNode->ToElement()->Attribute("status") == "disabled") {
            this->SetState(oss::NodeState::DISABLE);
        }
    }

    HostGroup::~HostGroup() {
    }

    namespace io {

        IoGroup::~IoGroup() {
        }
    }

    namespace i2c {

        I2cGroup::~I2cGroup() {
        }
    }

    namespace can {

        CanGroup::~CanGroup() {
        }
    }

    namespace spi {

        SpiGroup::~SpiGroup() {
        }
    }

    namespace uart {

        UartGroup::~UartGroup() {
        }
    }

    namespace ethernet {

        EthernetGroup::~EthernetGroup() {
        }
    }
}