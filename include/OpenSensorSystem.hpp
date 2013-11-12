/**
 * @file OpenSensorSystem.hpp
 *
 * @author thomas
 *
 * @date 1. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OPENSENSORSYSTEM_HPP
#define	OPENSENSORSYSTEM_HPP

// Debug Warning
#ifdef DEBUG
#warning "DEBUG Modus Enabled!"
#endif

/// General
#include "OssTree.hpp"
#include "OssGroups.hpp"
#include "OssRoot.hpp"
#include "OssRootNode.hpp"

#include "OssSpecialFunctions.hpp"
#include "OssConstants.hpp"

/// LUA
#include "lua/OssLuaSensorScript.hpp"

/// Sensor
#include "sensor/OssSensor.hpp"

/// IO

/// I2C
#include "i2c/OssI2cHost.hpp"
#include "i2c/OssI2cSlave.hpp"

/// SPI

/// CAN

/// UART

/// ETHERNET

#endif	/* OPENSENSORSYSTEM_HPP */

