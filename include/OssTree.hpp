/**
 * @file OssTree.hpp
 *
 * @author thomas
 *
 * @date 1. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSTREE_HPP
#define	OSSTREE_HPP

#include <set>
#include <string>
#include <tr1/memory>

namespace oss {

    namespace tree {

        /**
         * @brief represent a tree-structure
         */
        class TreeNode {
        public:

            TreeNode();

            explicit TreeNode(std::string newName) {
                this->SetName(newName);
            }

            TreeNode(const TreeNode &orig);

            virtual ~TreeNode();

            /**
             * @brief Add a new child-element
             *
             * @param childNode The new Node
             */
            virtual void AddChildNode(std::tr1::shared_ptr<TreeNode> childNode) {
                this->childNodes.insert(childNode);
            }

            /**
             * @brief Remove a child-element
             *
             * @param childNode shared_ptr of the element
             */
            virtual void RemoveChildNode(std::tr1::shared_ptr<TreeNode> childNode) {
                this->childNodes.erase(childNode);
            }

            /**
             * @brief Remove a child-element
             *
             * @param childName Name of the child element
             */
            virtual void RemoveChildNode(const std::string childName) {
                this->childNodes.erase(this->GetChildNode(childName));
            }

            /**
             * @brief Get a child element
             *
             * @param childName Name of the child element
             * @return shared_ptr with child element
             *
             * @warning When the name was multiply used, only the first found element would get return
             * @throw When the element would not found
             */
            std::tr1::shared_ptr<TreeNode> GetChildNode(const std::string childName);

            /**
             * @brief Get a child element
             *
             * @param id Number of the element
             * @return shared_ptr with child element
             *
             * @throw When id is to high (bigger as the amount of child nodes)
             */
            std::tr1::shared_ptr<TreeNode> GetChildNode(const unsigned int id);

            /**
             * @brief Set name of the Element
             *
             * @param newName new Name
             */
            void SetName(const std::string _name) {
                this->name = _name;
            }

            /**
             * @brief Get name of the Element
             *
             * @return Name of Element
             */
            std::string GetName(void) const {
                return this->name;
            }

            /**
             * @brief Return number of Child Elements
             *
             * @return Number of Child Elements
             */
            unsigned int size() const {
                this->childNodes.size();
            }

        public:

            /**
             * @brief Generate a graphical output of the Node and all Child-Nodes
             *
             * @param deep The maximum output-deep befor the function would stop
             * @return A string who contain the full tree-network
             *
             * @warning This Function is recursiv, in worst case the function go so long like deep != 0
             */
            std::string DrawTree(const unsigned int deep = 100) const;

        private:
            std::set<std::tr1::shared_ptr<TreeNode> > childNodes;

            std::string name; // Name of Node
        };
    }
}

#endif	/* OSSTREE_HPP */

