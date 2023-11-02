/**
 * CppCommon - Header-only library of common C++ functions and little helpers.
 * 
 * Author: Christian Koch
 * 
 * Copyright: This is licenced under the MIT licence. See "LICENCE"-file
 */
#pragma once

#include "math_common.hpp"

#include <vector>

namespace common {
namespace math {

/**
 * @brief Convert from radiant to degrees
 * 
 * @param rad angle in radiant
 * @return double angle in degrees
 */
double r2d(double rad)
{
    return 180.0 / M_PI * rad;
}

/**
 * @brief Convert from radiant to degrees
 * 
 * @param rad angle in radiant
 * @return float angle in degrees
 */
float r2d(float rad)
{
    return 180.0f / M_PIf * rad;
}

/**
 * @brief Convert from degree to radiant
 * 
 * @param deg angle in degree
 * @return double angle in radiant
 */
double d2r(double deg)
{
    return M_PI / 180.0 * deg;
}

/**
 * @brief Convert from degree to radiant
 * 
 * @param deg angle in degree
 * @return float angle in radiant
 */
float d2r(float deg)
{
    return M_PIf / 180.0f * deg;
}

} // namespace math
} // namespace common