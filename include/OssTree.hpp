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
#include <tr1/memory>
#include <map>
#include <string>
#include <sstream>

namespace oss {

    namespace tree {

        /**
         * @brief represent a tree-structure
         */
        class TreeNode {
        public:

            TreeNode();

            explicit TreeNode(std::string newName);

            TreeNode(const TreeNode &orig);

            virtual ~TreeNode();

            /**
             * @brief Add a new child-element
             *
             * @param childNode The new Node
             */
            virtual void AddChildNode(std::tr1::shared_ptr<TreeNode> childNode) {
                this->childNodes.insert(childNode);
                childNode->SetParrentNode(this);
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
             * @brief Get The Parrent Node of this Element
             *
             * @return Pointer to Parrent
             */
            const TreeNode * const GetParrentNode() const {
                return this->parentNode;
            }

            /**
             * @brief Set Pointer to Parrent Node
             *
             * @param _parentNode
             */
            void SetParrentNode(TreeNode *_parentNode) {
                this->parentNode = _parentNode;
            }

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
            unsigned int GetChildSize() const {
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

        public:

            void SetVariable(std::string name, const std::string variable) {
                this->variables[name] = variable;
            }

            std::string GetVariable(std::string name) const {
                if (this->GetConstante(this->variables[name]) == ("")) {
                    return this->variables[name];
                } else {
                    return this->GetConstante(this->variables[name]);
                }
            }

            double GetVariableAsDouble(std::string name) const {
                std::stringstream ss;
                ss << this->GetVariable(name);
                double helpVariable;
                ss >> helpVariable;
                return helpVariable;
            }

        public:

            void SetConstante(std::string name, const std::string constant) {
                this->constants[name] = constant;
            }

            std::string GetConstante(std::string name) const {
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

        private:
            std::set<std::tr1::shared_ptr<TreeNode> > childNodes;
            TreeNode const *parentNode;

            std::string name; // Name of Node


            mutable std::map<std::string, std::string> variables;
            mutable std::map<std::string, std::string> constants;
        };
    }
}

#endif	/* OSSTREE_HPP */

