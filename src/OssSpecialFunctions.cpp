/**
 * @file OssSpecialFunctions.cpp
 *
 * @author thomas
 *
 * @date 24. August 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#include <string>
#include <sstream>

#include "../include/OssSpecialFunctions.hpp"

namespace oss {
    namespace specialFunctions {
        namespace io {

            double GetClockSpeedFromString(const std::string clock) {

                int i = 0;
                for (; (isdigit(clock.at(i)) || ispunct(clock.at(i))) && i < clock.length(); i++);

                std::string suffix = clock.substr(i, clock.length() - i);

                std::stringstream ss;
                ss << clock.substr(0, i);
                double clockSpeed = 0;
                ss >> clockSpeed;

                if (suffix == "Hz" || suffix == "") {
                } else if (suffix == "kHz") {
                    clockSpeed *= 1e3;
                } else if (suffix == "MHz") {
                    clockSpeed *= 1e6;
                } else if (suffix == "GHz") {
                    clockSpeed *= 1e9;
                } else {
                    clockSpeed = 0;
                }

                return clockSpeed;
            }
        }
    }
}

