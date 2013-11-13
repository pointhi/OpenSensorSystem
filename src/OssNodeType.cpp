/**
 * @file OssNodeType.cpp
 *
 * @author thomas
 *
 * @date 13. November 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#include "../include/OssNodeType.hpp"

#include <tr1/memory>

#include <luabind/class.hpp>

#include "../include/OpenSensorSystem.hpp"

namespace oss {

    NodeType::NodeType() {
    }

    NodeType::NodeType(const NodeType& orig) {
    }

    NodeType::~NodeType() {
    }

    void NodeType::RegisterInLua(luabind::class_<NodeType>& x) {
        x.enum_("NodeTypes")
                [
                luabind::value("_NULL", oss::NodeType::_NULL),

                luabind::value("oss_root", oss::NodeType::oss_root),
                luabind::value("oss_rootNode", oss::NodeType::oss_rootNode),

                luabind::value("oss_i2c_Host", oss::NodeType::oss_i2c_Host),
                luabind::value("oss_i2c_Slave", oss::NodeType::oss_i2c_Slave),
                luabind::value("oss_i2c_SmbSlave", oss::NodeType::oss_i2c_SmbSlave),

                luabind::value("oss_lua_LuaSensorScript", oss::NodeType::oss_lua_LuaSensorScript),

                luabind::value("oss_sensor_Sensor", oss::NodeType::oss_sensor_Sensor)
                ];
    }

    NodeType::NodeTypes NodeType::ReturnNodeType(std::tr1::shared_ptr<oss::tree::TreeNode> _Node) {

        if (std::tr1::dynamic_pointer_cast<oss::RootNode>(_Node)) { // Root
            return NodeType::oss_rootNode;
        } else if (std::tr1::dynamic_pointer_cast<oss::Root>(_Node)) {
            return NodeType::oss_root;
        } else if (std::tr1::dynamic_pointer_cast<oss::i2c::Host>(_Node)) { // I2C
            return NodeType::oss_i2c_Host;
        } else if (std::tr1::dynamic_pointer_cast<oss::i2c::Slave>(_Node)) {
            return NodeType::oss_i2c_Slave;
        } else if (std::tr1::dynamic_pointer_cast<oss::i2c::SmbSlave>(_Node)) {
            return NodeType::oss_i2c_SmbSlave;
        } else if (std::tr1::dynamic_pointer_cast<oss::sensor::Sensor>(_Node)) { // Sensor
            return NodeType::oss_sensor_Sensor;
        } else if (std::tr1::dynamic_pointer_cast<oss::lua::LuaSensorScript>(_Node)) { // Lua
            return NodeType::oss_lua_LuaSensorScript;
        }
        // Type could't specify
        return NodeType::_NULL;
    }

}