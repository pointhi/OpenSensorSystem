/**
 * @file OssConstants.hpp
 *
 * @author thomas
 *
 * @date 16. September 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSCONSTANTS_HPP
#define	OSSCONSTANTS_HPP

#include <string>

namespace oss {
    namespace constants {
        namespace variableNames {
            static const std::string ObjectName("name");
            namespace variousVariables {
                static const std::string ConstantVariableValue("value");
            }
        }
        namespace xmlElementNames {
            static const std::string RootElementName("root");
            namespace hostElements {
                static const std::string I2c("i2c");
                static const std::string Can("can");
                static const std::string Spi("spi");
                static const std::string Uart("uart");
                static const std::string Io("io");
                static const std::string Ethernet("ethernet");
            }
            namespace i2cElements {
                static const std::string I2cSlave("i2c-slave");
                static const std::string SmbSlave("smb-slave");
            }
            namespace luaElements {
                static const std::string LuaScript("lua-script");
            }
            namespace sensorElements {
                static const std::string GeneralSensor("sensor");
            }
            namespace variousElements {
                static const std::string Constants("define");
            }
        }
    }
}

#endif	/* OSSCONSTANTS_HPP */

