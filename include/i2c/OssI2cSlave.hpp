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

#include "../OssGroups.hpp"

/**
 * \brief
 */
namespace oss {
    namespace i2c {

        class Slave : public oss::i2c::I2cGroup {
        public:
            Slave();
            explicit Slave(std::string newName);
            Slave(const Slave &orig);
            virtual ~Slave();

            virtual void parseXml(tinyxml2::XMLNode * const xmlNode);

        protected:
            void parseMainXmlParameter(tinyxml2::XMLNode * const xmlNode);
        };
    }
}

#endif	/* OSSI2CSLAVE_HPP */

