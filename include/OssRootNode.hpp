/**
 * @file OssRootNode.hpp
 *
 * @author thomas
 *
 * @date 24. Juli 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSROOTNODE_HPP
#define	OSSROOTNODE_HPP

#include <string>
#include <vector>

#include <tr1/memory>

#include "OssGroups.hpp"
#include "OssTree.hpp"

namespace oss {

    class RootNode : public oss::MainTreeGroup {
    public:
        RootNode();
        virtual ~RootNode();

        virtual void AddChildNode(std::tr1::shared_ptr<oss::HostGroup> childNode) {
            this->TreeNode::AddChildNode(childNode);
        }

        virtual void RemoveChildNode(std::tr1::shared_ptr<oss::HostGroup> childNode) {
            this->TreeNode::RemoveChildNode(childNode);
        }

        virtual void parseXml(tinyxml2::XMLNode * const xmlNode);
        void parseXml(std::string filePath);

    public:

        /**
         * @brief Get the pointer of a Sensor Element
         *
         * @param name Name of the Sensor
         *
         * @return Shared Pointer of the Sensor
         *
         * @warning When the name was multiply used, only the first found element would get return
         * @throw When the element would not found
         */
        oss::sensor::SensorGroup * const GetSensor(const std::string name) const;

        /**
         * @brief Get the pointer of a Sensor Element
         *
         * @param id ID of Sensor
         *
         * @return Shared Pointer of the Sensor
         * @throw When id is to high (bigger as the amount of child nodes)
         */
        oss::sensor::SensorGroup * const GetSensor(const unsigned int id) const;

        /**
         * @brief Add a Sensor to the List
         *
         * @param _sensorObject Shared Pointer to this object
         *
         * @todo solv Segmentation fault
         */
        void AddSensor(oss::sensor::SensorGroup* _sensorObject) {
            //            this->sensorList.insert(_sensorObject);
            std::cout << "set sensor" << std::endl;
        }

        /**
         * @brief Remove a Sensor from the List
         *
         * @param _sensorObject Shared Pointer to this object
         *
         * @todo solv Segmentation fault
         */
        void RemoveSensor(oss::sensor::SensorGroup* _sensorObject) {
            //            this->sensorList.erase(_sensorObject);
            std::cout << "remove sensor" << std::endl;
        }

        /**
         * @brief Return number of Sensor Elements
         *
         * @return Number of Sensor Elements
         */
        unsigned int GetSensorSize() const {
            return this->sensorListOld.size();
        }

    private:
        RootNode(const RootNode &orig);

        /**
         * @todo replace with vector or other container
         */
        std::set<std::tr1::weak_ptr<oss::sensor::SensorGroup> > sensorList;
        std::set<oss::sensor::SensorGroup*> sensorListOld;
    };
}
#endif	/* OSSROOTNODE_HPP */

