/**
 * @file OssRootNode.hpp
 *
 * @author thomas
 *
 * @date 24. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSROOTNODE_HPP
#define	OSSROOTNODE_HPP

#include <string>

#include "OssGroups.hpp"
#include "OssTree.hpp"

namespace oss {

    /**
     * \brief
     */

    class RootNode : public oss::MainTreeGroup {
    public:
        RootNode();
        virtual ~RootNode();

        virtual void AddChildNode(std::tr1::shared_ptr<oss::HostGroup> childNode) {
            this->TreeNode::AddChildNode(childNode);
        }

        virtual void RemoveChildNode(std::tr1::shared_ptr<oss::HostGroup> childNode) {
            this->TreeNode::RemoveChildNode(childNode);
        }

        virtual void parseXml(tinyxml2::XMLNode * const xmlNode);
        void parseXml(std::string filePath);

    private:
        RootNode(const RootNode &orig);
    };
}
#endif	/* OSSROOTNODE_HPP */

