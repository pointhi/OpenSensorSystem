/**
 * @file OssHostGroup.hpp
 *
 * @author thomas
 *
 * @date 1. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSHOSTGROUP_HPP
#define	OSSHOSTGROUP_HPP

#include "OssTree.hpp"
#include <iostream>

namespace tinyxml2 {
    class XMLNode;
}

/**
 * @brief General Namespace of the OpenSensorSystem
 */
namespace oss {

    namespace NodeState {

        /**
         * @brief Represent the different states which a node can have
         */
        enum NodeState {
            DISABLE = 0, WORKING = 1, NOT_CONNECTED, WAITING, OUT_OF_RANGE
        };
    }

    /**
     * @brief General Class who contain all special functions
     */
    class MainTreeGroup : public oss::tree::TreeNode {
    public:

        MainTreeGroup() {
            this->SetState(oss::NodeState::WAITING);
        }

        /**
         * @brief Load the class-structure from a xml-file
         * @param xmlNode Node on who would be worked
         *
         * @help http://www.grinninglizard.com/tinyxml2docs/index.html
         */
        virtual void parseXml(tinyxml2::XMLNode * const xmlNode) = 0;

        void SetState(oss::NodeState::NodeState NewState) {
            this->State = NewState;
        }

        oss::NodeState::NodeState GetState() const {
            return this->State;
        }

    private:
        NodeState State;
    };

    /**
     * @brief General Class in which are the parent for all Host Classes
     */
    class HostGroup : public oss::MainTreeGroup {
    };

    namespace io {

        /**
         * @brief General Class in which are the parent for all IO-Slave Classes
         */
        class IoGroup : public oss::MainTreeGroup {
        };
    }

    namespace i2c {

        /**
         * @brief General Class in which are the parent for all I2C-Slave Classes
         */
        class I2cGroup : public oss::MainTreeGroup {
        };
    }

    namespace can {

        /**
         * @brief General Class in which are the parent for all CAN-Slave Classes
         */
        class CanGroup : public oss::MainTreeGroup {
        };
    }

    namespace spi {

        /**
         * @brief General Class in which are the parent for all SPI-Slave Classes
         */
        class SpiGroup : public oss::MainTreeGroup {
        };
    }

    namespace uart {

        /**
         * @brief General Class in which are the parent for all UART-Slave Classes
         */
        class UartGroup : public oss::MainTreeGroup {
        };
    }

    namespace ethernet {

        /**
         * @brief General Class in which are the parent for all Ethernet-Slave Classes
         */
        class EthernetGroup : public oss::MainTreeGroup {
        };
    }
}

#endif	/* OSSHOSTGROUP_HPP */

