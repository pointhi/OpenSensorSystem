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

struct lua_State;

namespace oss {
    namespace lua {

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

            void RegisterInLua(luabind::class_<LuaSensorScript>& x);

        protected:

            // Special functions for Lua to read variables from parrents and childs.

            const std::string GetVariableFromParrent(std::string _variableName) const {
                return this->GetParrentNode()->GetVariable(_variableName);
            }

            const std::string GetVariableFromChildNode(std::string _variableName, const std::string _childName) {
                return this->GetChildNode(_childName)->GetVariable(_variableName);
            }

            const std::string GetVariableFromChildNode(std::string _variableName, const unsigned int _childId) {
                return this->GetChildNode(_childId)->GetVariable(_variableName);
            }

            const oss::NodeType::NodeTypes GetNodeTypeFromParrent() const {
                return oss::NodeType::ReturnNodeType(this->GetParrentNode());
            }

            const oss::NodeType::NodeTypes GetNodeTypeFromChildNode(const std::string _childName) {
                return oss::NodeType::ReturnNodeType(this->GetChildNode(_childName));
            }

            const oss::NodeType::NodeTypes GetNodeTypeFromChildNode(const unsigned int _childId) {
                return oss::NodeType::ReturnNodeType(this->GetChildNode(_childId));
            }

        private:

            lua_State *LuaState;

        };
    }
}
#endif	/* OSSLUASENSORSCRIPT_HPP */

