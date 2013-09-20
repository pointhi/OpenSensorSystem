/*
 * File:   OssSensor.hpp
 * Author: thomas
 *
 * Created on 20. September 2013, 14:12
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

