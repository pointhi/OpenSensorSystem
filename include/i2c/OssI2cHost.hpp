/**
 * @file OssI2cHost.hpp
 *
 * @author thomas
 *
 * @date 1. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSI2CHOST_HPP
#define	OSSI2CHOST_HPP

#include <vector>

#include "../OssGroups.hpp"
#include "../OssTree.hpp"


namespace tinyxml2 {
    class XMLNode;
}

namespace oss {
    namespace i2c {

        /**
         * @brief Represent an I2C Host
         */
        class Host : public oss::HostGroup {
        public:

            Host();

            explicit Host(std::string newName);

            Host(const Host &orig);

            virtual ~Host();

            virtual void AddChildNode(std::tr1::shared_ptr<oss::i2c::I2cGroup> childNode) {
                this->TreeNode::AddChildNode(childNode);
            }

            virtual void RemoveChildNode(std::tr1::shared_ptr<oss::i2c::I2cGroup> childNode) {
                this->TreeNode::RemoveChildNode(childNode);
            }

            virtual void parseXml(tinyxml2::XMLNode * const xmlNode);

        public:
            /**
             * @brief Set The I2C-adress for the Device
             *
             * @param i2cAdress Adress of the Slave
             *
             * @warning Does not work on all OS
             */
            void I2cSetAdress(const unsigned int i2cAdress);

            /**
             * @brief Write data to I2c-Slave
             *
             * @param i2cAdress Adress of the Slave
             * @param data Data which is written to Slave
             *
             * @warning Does not work on all OS
             * @todo Test Function (datasize)
             */
            void I2cWrite(const unsigned int i2cAdress, const std::vector<unsigned char> data);

            /**
             * @brief Read data from I2c-Slave
             *
             * @param i2cAdress Adress of the Slave
             * @param dataLenght Number of Data-Bits which would be read
             * @return Data which is readed from Slave
             *
             * @warning Does not work on all OS
             * @todo Test Function (datasize)
             */
            const std::vector<unsigned char> I2cRead(const unsigned int i2cAdress, const unsigned int dataLenght);

        private:

            void InitI2C();

        protected:

            signed int i2cHandler;

        };
    }
}

#endif	/* OSSI2CHOST_HPP */

