/**
 * @file OssSensor.hpp
 *
 * @author thomas
 *
 * @date 20. September 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSSENSOR_HPP
#define	OSSSENSOR_HPP

#include "../OssGroups.hpp"

namespace oss {
    namespace sensor {

        class Sensor : public SensorGroup {
        public:
            Sensor();
            Sensor(const Sensor& orig);
            virtual ~Sensor();

            virtual void parseXml(tinyxml2::XMLNode * const xmlNode);

            virtual void AddChildNode(std::tr1::shared_ptr<oss::EndTreeNode> childNode) {
                //                this->TreeNode::AddChildNode(childNode);
            }

            virtual void RemoveChildNode(std::tr1::shared_ptr<oss::EndTreeNode> childNode) {
                //                this->TreeNode::RemoveChildNode(childNode);9
            }

        private:

        };
    }
}

#endif	/* OSSSENSOR_HPP */

