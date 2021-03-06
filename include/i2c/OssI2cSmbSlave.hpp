/**
 * @file OssI2cSmbSlave.hpp
 *
 * @author thomas
 *
 * @date 17. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSI2CSMBSLAVE_HPP
#define	OSSI2CSMBSLAVE_HPP

#include "OssI2cSlave.hpp"

namespace oss {
    namespace i2c {

        /**
         * @brief Represent a SPI I2C Slave
         */
        class SmbSlave : public Slave {
        public:
            SmbSlave();
            explicit SmbSlave(std::string newName);
            SmbSlave(const SmbSlave &orig);
            virtual ~SmbSlave();

            virtual void AddChildNode(std::tr1::shared_ptr<oss::helpGroups::LuaAndSensorGroup> childNode) {
                this->TreeNode::AddChildNode(childNode);
            }

            virtual void RemoveChildNode(std::tr1::shared_ptr<oss::helpGroups::LuaAndSensorGroup> childNode) {
                this->TreeNode::RemoveChildNode(childNode);
            }

            virtual void parseXml(tinyxml2::XMLNode * const xmlNode);

        private:

        };
    }
}

#endif	/* OSSI2CSMBSLAVE_HPP */

