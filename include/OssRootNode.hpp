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
#include <algorithm>
#include <set>

#include <tr1/memory>

#include "OssGroups.hpp"
#include "OssTree.hpp"

namespace oss {

    /**
     * @brief Root Node, which control the different devices
     *
     * @warning You must initialize this object in an std::tr1::shared_ptr<oss::tree::TreeNode>, or simply using oss::Root
     */
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
         * @param _name Name of the Sensor
         *
         * @return Shared Pointer of the Sensor
         *
         * @warning When the name was multiply used, only the first found element would get return
         * @throw When the element would not found
         */
        std::tr1::shared_ptr<oss::sensor::SensorGroup> GetSensor(const std::string _name) const;

        /**
         * @brief Get the pointer of a Sensor Element
         *
         * @param _id ID of Sensor
         *
         * @return Shared Pointer of the Sensor
         * @throw When id is to high (bigger as the amount of child nodes)
         */
        std::tr1::shared_ptr<oss::sensor::SensorGroup> GetSensor(const unsigned int _id) const;

        /**
         * @brief Add a Sensor to the List
         *
         * @param _sensorObject Shared Pointer to this object
         *
         * @todo solv Segmentation fault
         */
        void AddSensor(std::tr1::weak_ptr<oss::sensor::SensorGroup> _sensorObject) {
            this->sensorList.insert(_sensorObject);
            //            std::cout << "set sensor" << std::endl;
        }

        /**
         * @brief Remove a Sensor from the List
         *
         * @param _sensorObject Shared Pointer to this object
         *
         * @todo solv Segmentation fault
         */
        void RemoveSensor(std::tr1::weak_ptr<oss::sensor::SensorGroup> _sensorObject) {
            this->sensorList.erase(_sensorObject);
            //            std::cout << "remove sensor" << std::endl;
        }

        /**
         * @brief Return number of Sensor Elements
         *
         * @return Number of Sensor Elements
         */
        unsigned int GetSensorSize();

    private:
        RootNode(const RootNode &orig);

        /**
         * @todo replace with vector or other container
         */
        std::set<std::tr1::weak_ptr<oss::sensor::SensorGroup> > sensorList;
    };
}
#endif	/* OSSROOTNODE_HPP */

