/**
 * @file OssLuaSensorScript.hpp
 *
 * @author thomas
 *
 * @date 19. September 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSLUASENSORSCRIPT_HPP
#define	OSSLUASENSORSCRIPT_HPP

#include "../OssGroups.hpp"
#include "../OssNodeType.hpp"
#include <luabind/class.hpp>

struct lua_State;

namespace oss {
    namespace lua {

        /**
         * @brief Class which can use lua-scripts
         */
        class LuaSensorScript : public oss::lua::LuaGroup {
        public:
            LuaSensorScript();
            virtual ~LuaSensorScript();

        private:
            LuaSensorScript(const LuaSensorScript& orig);

        protected:

            /**
             * @brief Load all necessary modules and functions
             */
            virtual void InitLua();

        public:

            virtual void InitChild();

            virtual void parseXml(tinyxml2::XMLNode * const xmlNode);

            virtual void AddChildNode(std::tr1::shared_ptr<oss::helpGroups::LuaAndSensorGroup> childNode) {
                this->TreeNode::AddChildNode(childNode);
            }

            virtual void RemoveChildNode(std::tr1::shared_ptr<oss::helpGroups::LuaAndSensorGroup> childNode) {
                this->TreeNode::RemoveChildNode(childNode);
            }

        public:

            virtual void RunNode();

        public:

            /**
             * @brief Register gerneral lua functions
             *
             * @param x luabind class
             */
            void RegisterInLua(luabind::class_<LuaSensorScript>& x);

        protected:
            // Special functions for Lua to read variables from parrents and childs.

            /**
             * @brief Get a Variable from the parrent
             *
             * @param _variableName Name of the Variable
             * @return The Variable
             */
            const std::string GetVariableFromParrent(std::string _variableName) const {
                return this->GetParrentNode()->GetVariable(_variableName);
            }

            /**
             * @brief Get a Variable from a Child
             *
             * @param _variableName Name of the Variable
             * @param _childName Name of the Child
             * @return The Variable
             */
            const std::string GetVariableFromChildNode(std::string _variableName, const std::string _childName) {
                return this->GetChildNode(_childName)->GetVariable(_variableName);
            }

            /**
             * @brief Get a Variable from a Child
             *
             * @param _variableName Name of the Variable
             * @param _childId Id of the Child
             * @return The Variable
             */
            const std::string GetVariableFromChildNode(std::string _variableName, const unsigned int _childId) {
                return this->GetChildNode(_childId)->GetVariable(_variableName);
            }

            /**
             * @brief Get the NodeType from the Parrent
             *
             * @return The Type of the Class
             */
            const oss::NodeType::NodeTypes GetNodeTypeFromParrent() const {
                return oss::NodeType::ReturnNodeType(this->GetParrentNode());
            }

            /**
             * @brief Get the NodeType from a Child
             *
             * @param _childName Name of the Child
             * @return The Type of the Class
             */
            const oss::NodeType::NodeTypes GetNodeTypeFromChildNode(const std::string _childName) {
                return oss::NodeType::ReturnNodeType(this->GetChildNode(_childName));
            }

            /**
             * @brief Get the NodeType from a Child
             *
             * @param _childId Id of the Child
             * @return The Type of the Class
             */
            const oss::NodeType::NodeTypes GetNodeTypeFromChildNode(const unsigned int _childId) {
                return oss::NodeType::ReturnNodeType(this->GetChildNode(_childId));
            }

        private:

            lua_State *LuaState;

            /**
             * @brief If false, the lua script will not be called
             */
            bool LuaScriptEnabled;

        };
    }
}
#endif	/* OSSLUASENSORSCRIPT_HPP */

