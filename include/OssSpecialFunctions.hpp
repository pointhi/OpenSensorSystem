/**
 * @file OssSpecialFunctions.hpp
 *
 * @author thomas
 *
 * @date 24. August 2013
 * @copyright GNU General Public License (GPL) 3.0
 */

#ifndef OSSSPECIALFUNCTIONS_HPP
#define	OSSSPECIALFUNCTIONS_HPP

#include <string>

namespace oss {
    namespace specialFunctions {
        namespace io {

            /**
             * @brief Convert an String with represent the speed into double
             *
             * @param clock String with represent the speed
             * @return The Clock-Speed in Hz
             */
            double GetClockSpeedFromString(const std::string Clock);
        }
    }
}

#endif	/* OSSSPECIALFUNCTIONS_HPP */

