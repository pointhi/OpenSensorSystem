/**
 * @file OssNodeType.hpp
 *
 * @author thomas
 *
 * @date 13. November 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSNODETYPE_HPP
#define	OSSNODETYPE_HPP

#include "OssTree.hpp"
#include <luabind/class.hpp>

namespace oss {

    class NodeType {
    private:
        NodeType();
        NodeType(const NodeType& orig);
        ~NodeType();

    public:

        // Enum, to represent each class

        enum NodeTypes {
            _NULL = 0,
            oss_root, oss_rootNode,
            oss_i2c_Host, oss_i2c_Slave, oss_i2c_SmbSlave,
            oss_lua_LuaSensorScript,
            oss_sensor_Sensor
        };

        static void RegisterInLua(luabind::class_<NodeType>& x);

        static NodeTypes ReturnNodeType(std::tr1::shared_ptr<oss::tree::TreeNode> _Node);
    };

}

#endif	/* OSSNODETYPE_HPP */

