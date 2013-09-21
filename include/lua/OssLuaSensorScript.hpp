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

namespace oss {
    namespace lua {

        class LuaSensorScript : public oss::lua::LuaGroup {
        public:
            LuaSensorScript();
            LuaSensorScript(const LuaSensorScript& orig);
            virtual ~LuaSensorScript();

            virtual void parseXml(tinyxml2::XMLNode * const xmlNode);

            virtual void AddChildNode(std::tr1::shared_ptr<oss::helpGroups::LuaAndSensorGroup> childNode) {
                this->TreeNode::AddChildNode(childNode);
            }

            virtual void RemoveChildNode(std::tr1::shared_ptr<oss::helpGroups::LuaAndSensorGroup> childNode) {
                this->TreeNode::RemoveChildNode(childNode);
            }

        private:

        };
    }
}
#endif	/* OSSLUASENSORSCRIPT_HPP */

