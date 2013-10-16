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

namespace oss {

    /**
     * @brief Root Element for the Tree
     */
    class Root {
    private:

        std::tr1::shared_ptr<oss::tree::TreeNode> RootNodeReference;
    public:

        Root() {
            RootNodeReference.reset(new oss::RootNode);
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
        oss::RootNode* operator->() const {
            return (dynamic_cast<oss::RootNode*> (RootNodeReference.get()));
        }

    };
}

#endif	/* OSSROOT_HPP */

