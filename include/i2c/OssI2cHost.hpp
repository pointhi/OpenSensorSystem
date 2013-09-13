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

#include "../OssGroups.hpp"
#include "../OssTree.hpp"

namespace tinyxml2 {
    class XMLNode;
}

namespace oss {
    namespace i2c {

        /**
         * @brief
         */

        class Host : public oss::HostGroup {
        public:

            Host();

            explicit Host(std::string newName) {
                this->SetName(newName);
            }

            Host(const Host &orig);

            virtual ~Host();

            virtual void AddChildNode(std::tr1::shared_ptr<oss::i2c::I2cGroup> childNode) {
                this->TreeNode::AddChildNode(childNode);
            }

            virtual void RemoveChildNode(std::tr1::shared_ptr<oss::i2c::I2cGroup> childNode) {
                this->TreeNode::RemoveChildNode(childNode);
            }

            virtual void parseXml(tinyxml2::XMLNode * const xmlNode);

            void SetDevicePath(std::string path);

            /**
             * @brief Convert string to clock-speed
             *
             * @param clock
             *
             * @bug comma doesn't func
             */
            void SetClockSpeed(std::string clock);
            void SetClockSpeed(double clock);

            std::string GetDevicePath() const {
                return this->devicePath;
            }

            double GetClockSpeed() const {
                return this->clockSpeed;
            }

        private:
            std::string devicePath;
            double clockSpeed;
        };
    }
}

#endif	/* OSSI2CHOST_HPP */

