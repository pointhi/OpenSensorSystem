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

#include <vector>
#include <tr1/memory>
#include <map>
#include <string>
#include <iostream>

namespace oss {

    namespace tree {

        /**
         * @brief represent a tree-structure
         */
        class TreeNode : public std::tr1::enable_shared_from_this<TreeNode> {
        public:

            TreeNode();

            explicit TreeNode(const std::string newName);

            TreeNode(const TreeNode &orig);

            virtual ~TreeNode();

        public:

            /**
             * @brief Would be called after insterting in array and setting root and element node
             */
            virtual void InitChild() {
            }

            /**
             * @brief Would be called to make an update of the data, and call when needed nodes deeper in the tree
             */
            virtual void RunNode() {
                for (int i = 0; i < this->childNodes.size(); i++) {
                    this->childNodes.at(i)->RunNode();
                }
            }

            /**
             * @brief Add a new child-element and set element and parrent reference Node
             *
             * @param childNode The new Node
             */
            virtual void AddChildNode(std::tr1::shared_ptr<TreeNode> _childNode) {
                this->childNodes.push_back(_childNode);
                _childNode->SetParrentNode(this->GetElementNode());
                _childNode->InitChild();
            }

            /**
             * @brief Remove a child-element
             *
             * @param childNode shared_ptr of the element
             */
            virtual void RemoveChildNode(std::tr1::shared_ptr<TreeNode> childNode) {
                for (int i = 0; i<this->childNodes.size(); i++) {
                    if (this->childNodes.at(i).get() == childNode.get()) {
                        this->RemoveChildNode(i);
                        break;
                    }
                }
            }

            /**
             * @brief Remove a child-element
             *
             * @param childId Id of the child element
             */
            void RemoveChildNode(const unsigned int childId) {
                this->childNodes.erase(this->childNodes.begin() + childId);
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
             * @brief Get The Parrent Node of this Element
             *
             * @return shared_ptr to Parrent
             */
            std::tr1::shared_ptr<TreeNode> GetParrentNode() const {
                return this->parentNode.lock();
            }

            /**
             * @brief Get The Root-Node of this Element
             *
             * @return shared_ptr to Root-Node
             */
            std::tr1::shared_ptr<TreeNode> GetRootNode() {
                if (!this->parentNode.expired()) {
                    return this->GetParrentNode()->GetRootNode();
                } else {
                    return this->GetElementNode();
                }
            }

            /**
             * @brief Set weak_ptr to Parrent Node
             *
             * @param _parentNode
             */
            void SetParrentNode(std::tr1::weak_ptr<TreeNode> _parentNode) {
                this->parentNode = _parentNode;
            }

            /**
             * @brief Get The Element Node of this Element
             *
             * @return shared_ptr to Element
             */
            std::tr1::shared_ptr<TreeNode> GetElementNode() {
                return this->shared_from_this();
            }

            /**
             * @brief Return number of Child Elements
             *
             * @return Number of Child Elements
             */
            unsigned int GetChildSize() const {
                return this->childNodes.size();
            }

        public:

            /**
             * @brief Generate a graphical output of the Node and all Child-Nodes
             *
             * @param drawScriptParts enable or dissable rendering of scripts in output tree, not implemented yet!
             * @param treeString Define the Characters, which would be drawn before the name of the element
             * @param treeChildString Define the Characters, which would be drawn at the start, when the element is deeper than the start-node
             * @param deep The maximum output-deep befor the function would stop
             * @return A string who contain the full tree-network
             *
             * @warning This Function is recursiv, in worst case the function go so long like deep != 0
             */
            std::string DrawTree(const bool drawScriptParts = true, const std::string treeString = "|- ", const std::string treeChildString = "  ", const unsigned int deep = 100) const;

        public:

            /**
             * @brief Set The Value of a Variable
             * @note When The Variable not exist, it would generate a new one
             *
             * @param name Name of the Variable
             * @param variable Value of the variable
             */
            void SetVariable(const std::string name, const std::string variable) {
                this->variables[name] = variable;
            }

            /**
             * @brief Get a Variable
             * @note When the Value of the variable contain a string, which match with an constant, it would repleaced with it
             *
             * @param name Name of the Variable
             * @return Value of the Variable
             */
            const std::string GetVariable(const std::string name) const;

            /**
             * @brief Get a Variable as Double
             * @note When the Value of the variable contain a string, which match with an constant, it would repleaced with it
             *
             * @param name Name of the Variable
             * @return Value of the Variable as Double
             */
            const double GetVariableAsDouble(const std::string name) const;

        public:

            /**
             * @brief Set The Value of a Constant
             * @note When The Constant not exist, it would generate a new one
             *
             * @param name Name of the Constant
             * @param constant Value of the Constant
             */
            void SetConstante(const std::string name, const std::string constant);

            /**
             * @brief Get a Constant
             * @warning This is a recursiv function, which would call all parrent nodes until matching or entering the root node
             *
             * @param name Name of the Constant
             * @return Value of the Constant, "" when no Constant exists
             */
            const std::string GetConstante(const std::string name) const;

        private:
            std::vector<std::tr1::shared_ptr<TreeNode> > childNodes;
            std::tr1::weak_ptr<TreeNode> parentNode, elementNode;

            mutable std::map<std::string, std::string> variables;
            mutable std::map<std::string, std::string> constants;
        };
    }
}

#endif	/* OSSTREE_HPP */

