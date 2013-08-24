/**
 * @file OssGroups.cpp
 *
 * @author thomas
 *
 * @date 24. August 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#include "../include/OssGroups.hpp"

namespace oss {

    MainTreeGroup::~MainTreeGroup() {
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