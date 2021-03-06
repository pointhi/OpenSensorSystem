/**
 * @file OssI2cSlave.hpp
 *
 * @author thomas
 *
 * @date 17. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSI2CSLAVE_HPP
#define	OSSI2CSLAVE_HPP

#include <string>
#include <vector>

#include "../OssGroups.hpp"

#include <luabind/class.hpp>

namespace oss {
    namespace i2c {

        /**
         * @brief Represent a normal I2C Slave
         */
        class Slave : public oss::i2c::I2cGroup {
        public:
            Slave();
            explicit Slave(std::string newName);
            Slave(const Slave &orig);
            virtual ~Slave();

            virtual void parseXml(tinyxml2::XMLNode * const xmlNode);

            virtual void AddChildNode(std::tr1::shared_ptr<oss::lua::LuaGroup> childNode) {
                this->TreeNode::AddChildNode(childNode);
            }

            virtual void RemoveChildNode(std::tr1::shared_ptr<oss::lua::LuaGroup> childNode) {
                this->TreeNode::RemoveChildNode(childNode);
            }

            void parseMainXmlParameter(tinyxml2::XMLNode * const xmlNode);

        public:
            void RegisterInLua(luabind::class_<Slave>& x);

            std::vector<unsigned char> readFromSlave(unsigned int _bits);
            void writeToSlave(std::vector<unsigned char> _writeData);
        };
    }
}

#endif	/* OSSI2CSLAVE_HPP */

