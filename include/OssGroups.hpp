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
        virtual ~MainTreeGroup() = 0;

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

        /**
         * @brief Load all Variables (Attributes from XML-Node) into the Class
         *
         * @param xmlNode Node on who would be worked
         */
        virtual void parseVariablesFromXml(tinyxml2::XMLNode * const xmlNode);

        /**
         * @brief Load all Constants from the XML-Node into the Class
         *
         * @param xmlNode Node on who would be worked
         */
        void parseConstantsFromXml(tinyxml2::XMLNode * const xmlNode);

    public:

        void SetState(oss::NodeState::NodeState _state) {
            this->state = _state;
        }

        oss::NodeState::NodeState GetState() const {
            return this->state;
        }

    protected:
        void parseMainXmlParameter(tinyxml2::XMLNode * const xmlNode);

    private:
        oss::NodeState::NodeState state;
    };

    /**
     * @brief General Class in which are the parent for all Host Classes
     */
    class HostGroup : public oss::MainTreeGroup {
    public:
        virtual ~HostGroup() = 0;
    };

    namespace io {

        /**
         * @brief General Class in which are the parent for all IO-Slave Classes
         */
        class IoGroup : public oss::MainTreeGroup {
        public:
            virtual ~IoGroup() = 0;
        };
    }

    namespace i2c {

        /**
         * @brief General Class in which are the parent for all I2C-Slave Classes
         */
        class I2cGroup : public oss::MainTreeGroup {
        public:
            virtual ~I2cGroup() = 0;
        };
    }

    namespace can {

        /**
         * @brief General Class in which are the parent for all CAN-Slave Classes
         */
        class CanGroup : public oss::MainTreeGroup {
        public:
            virtual ~CanGroup() = 0;
        };
    }

    namespace spi {

        /**
         * @brief General Class in which are the parent for all SPI-Slave Classes
         */
        class SpiGroup : public oss::MainTreeGroup {
        public:
            virtual ~SpiGroup() = 0;
        };
    }

    namespace uart {

        /**
         * @brief General Class in which are the parent for all UART-Slave Classes
         */
        class UartGroup : public oss::MainTreeGroup {
        public:
            virtual ~UartGroup() = 0;
        };
    }

    namespace ethernet {

        /**
         * @brief General Class in which are the parent for all Ethernet-Slave Classes
         */
        class EthernetGroup : public oss::MainTreeGroup {
        public:
            virtual ~EthernetGroup() = 0;
        };
    }

    namespace lua {

        /**
         * @brief General Class which are the parent for all Lua Classes
         */
        class LuaGroup : public oss::MainTreeGroup {
        public:
            virtual ~LuaGroup() = 0;
        };

        /**
         * @brief General Class which are the parent for all General-Lua-Script Classes
         */
        class LuaSensorScriptGroup : public oss::lua::LuaGroup {
        public:
            virtual ~LuaSensorScriptGroup() = 0;
        };
    }

    namespace sensor {

        /**
         * @brief General Class in which are the parent for all Sensor Classes
         */
        class SensorGroup : public oss::lua::LuaSensorScriptGroup {
        public:
            virtual ~SensorGroup() = 0;
        };
    }
}

#endif	/* OSSHOSTGROUP_HPP */

