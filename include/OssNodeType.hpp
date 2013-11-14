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

    /**
     * @brief Representing Classes which are based on oss::tree::treeNode
     */
    class NodeType {
    private:
        NodeType();
        NodeType(const NodeType& orig);
        ~NodeType();

    public:

        /**
         * @brief Represent all Classes, to make it easier to check which one is used
         */
        enum NodeTypes {
            _NULL = 0,
            oss_root, oss_rootNode,
            oss_i2c_Host, oss_i2c_Slave, oss_i2c_SmbSlave,
            oss_lua_LuaSensorScript,
            oss_sensor_Sensor
        };

        /**
         * @brief Register enums in lua-script
         *
         * @param x luabind class
         */
        static void RegisterInLua(luabind::class_<NodeType>& x);

        /**
         * @brief Return the Enum Element, which represent the given class pointer
         *
         * @param _Node Class pointer to check
         */
        static NodeTypes ReturnNodeType(std::tr1::shared_ptr<oss::tree::TreeNode> _Node);
    };

}

#endif	/* OSSNODETYPE_HPP */

