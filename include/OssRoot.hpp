/**
 * @file OssRoot.hpp
 *
 * @author thomas
 *
 * @date 16. Oktober 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSROOT_HPP
#define	OSSROOT_HPP

#include "OssRootNode.hpp"
#include <tr1/memory>
#include <memory>

namespace oss {

    /**
     * @brief Root Element for the Tree
     */
    class Root {
    private:
        std::tr1::shared_ptr<oss::RootNode> RootNodeReference;

    public:

        /**
         * @brief Generate a new oss::RootNode object
         */
        Root() {
            // Is required because of std::tr1::enable_shared_from_this as parrent of oss::tree::TreeNode
            std::tr1::shared_ptr<oss::tree::TreeNode> helpPtr(new oss::RootNode);
            // Converting to right Type
            this->RootNodeReference = std::tr1::dynamic_pointer_cast<oss::RootNode>(helpPtr);
        }

        virtual ~Root() {
        }

    private:

        Root(const Root &orig) {
        }

    public:

        /**
         * @brief Get RootNode Element as pointer
         *
         * @todo Modify it to a shared_ptr
         */
        std::tr1::shared_ptr<oss::RootNode> operator->() const {
            return RootNodeReference;
        }

    };
}

#endif	/* OSSROOT_HPP */

