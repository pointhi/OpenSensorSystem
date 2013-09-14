/**
 * @file OssTree.cpp
 *
 * @author thomas
 *
 * @date 1. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#include <set>
#include <string>
#include <tr1/memory>
#include <sstream>
#include <iostream>

#include "../include/OssTree.hpp"

namespace oss {
    namespace tree {

        TreeNode::TreeNode() : parentNode(NULL) {
        }

        TreeNode::TreeNode(std::string newName) : parentNode(NULL) {
            this->SetVariable("name", newName);
        }

        TreeNode::TreeNode(const TreeNode& orig) {
        }

        TreeNode::~TreeNode() {
        }

        std::tr1::shared_ptr<TreeNode> TreeNode::GetChildNode(const std::string childName) {
            for (std::set<std::tr1::shared_ptr<TreeNode> >::iterator it = this->childNodes.begin()
                    ; it != this->childNodes.end()
                    ; it++
                    ) {

                if ((*it).get()->GetVariable("name") == childName) {
                    return *it;
                }
            }
            throw "No Child Element found";
        }

        std::tr1::shared_ptr<TreeNode> TreeNode::GetChildNode(const unsigned int id) {
            if (id<this->childNodes.size()) {
                std::set<std::tr1::shared_ptr<TreeNode> >::iterator it = this->childNodes.begin();

                for (unsigned int i = 0; i < id; it++, i++);

                return *it;
            }
            throw "Id to high";
        }

        std::string TreeNode::DrawTree(const unsigned int deep) const {

            // String who would be drawn before the Name
            const std::string constTreeString = "- ";

            // String who would be drawn in every row of a child Node
            const std::string constChildString = "--";

            // Generate the ReturnString
            std::string returnTree(constTreeString + this->GetVariable("name"));

            // Get Strings from child-nodes and formate them
            if (deep > 0) {
                std::string childTree;

                for (std::set<std::tr1::shared_ptr<TreeNode> >::iterator it = this->childNodes.begin()
                        ; it != this->childNodes.end()
                        ; it++
                        ) {

                    childTree.clear();
                    childTree = (*it)->DrawTree(deep - 1);

                    // Draw a child-string in every row of a child Node
                    for (unsigned int i = childTree.find(constTreeString)
                            ; i < childTree.size()
                            ; i = childTree.find(constTreeString, i + constChildString.size() + 1)
                            ) {
                        childTree.insert(i, constChildString);
                    }

                    returnTree += "\n" + childTree;
                }
            }

            return returnTree;
        }

        std::string TreeNode::GetVariable(std::string name) const {
            if (this->GetConstante(this->variables[name]) == ("")) {
                return this->variables[name];
            } else {
                return this->GetConstante(this->variables[name]);
            }
        }

        double TreeNode::GetVariableAsDouble(std::string name) const {
            std::stringstream ss;
            ss << this->GetVariable(name);
            double helpVariable;
            ss >> helpVariable;
            return helpVariable;
        }

        void TreeNode::SetConstante(std::string name, const std::string constant) {
            this->constants[name] = constant;
        }

        std::string TreeNode::GetConstante(std::string name) const {
            if (this->constants.count(name)) {
                return this->constants[name];
            } else {
                if (this->GetParrentNode()) {
                    return this->GetParrentNode()->GetConstante(name);
                } else {
                    return ("");
                }
            }
        }

    }
}