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

    namespace tree {
        class TreeNode;
    }

    namespace sensor {

        class Sensor : public SensorGroup {
        public:
            //            Sensor();

            explicit Sensor(const oss::tree::TreeNode *parentNode);

            virtual ~Sensor();

            virtual void parseXml(tinyxml2::XMLNode * const xmlNode);

            virtual void AddChildNode(std::tr1::shared_ptr<oss::EndTreeNode> childNode) {
                //                this->TreeNode::AddChildNode(childNode);
            }

            virtual void RemoveChildNode(std::tr1::shared_ptr<oss::EndTreeNode> childNode) {
                //                this->TreeNode::RemoveChildNode(childNode);9
            }

        private:
            Sensor(const Sensor& orig);
        };
    }
}

#endif	/* OSSSENSOR_HPP */

