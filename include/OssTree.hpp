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

            /**
             * @brief Set The Value of a Variable
             * @note When The Variable not exist, it would generate a new one
             *
             * @param name Name of the Variable
             * @param variable Value of the variable
             */
            void SetVariable(std::string name, const std::string variable) {
                this->variables[name] = variable;
            }

            /**
             * @brief Get a Variable
             * @note When the Value of the variable contain a string, which match with an constant, it would repleaced with it
             *
             * @param name Name of the Variable
             * @return Value of the Variable
             */
            std::string GetVariable(std::string name) const;

            /**
             * @brief Get a Variable as Double
             * @note When the Value of the variable contain a string, which match with an constant, it would repleaced with it
             *
             * @param name Name of the Variable
             * @return Value of the Variable as Double
             */
            double GetVariableAsDouble(std::string name) const;

        public:

            /**
             * @brief Set The Value of a Constant
             * @note When The Constant not exist, it would generate a new one
             *
             * @param name Name of the Constant
             * @param constant Value of the Constant
             */
            void SetConstante(std::string name, const std::string constant);

            /**
             * @brief Get a Constant
             * @warning This is a recursiv function, which would call all parrent nodes until matching or entering the root node
             *
             * @param name Name of the Constant
             * @return Value of the Constant, "" when no Constant exists
             */
            std::string GetConstante(std::string name) const;

        private:
            std::set<std::tr1::shared_ptr<TreeNode> > childNodes;
            TreeNode const *parentNode;

            mutable std::map<std::string, std::string> variables;
            mutable std::map<std::string, std::string> constants;
        };
    }
}

#endif	/* OSSTREE_HPP */

