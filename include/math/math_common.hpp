/**
 * CppCommon - Header-only library of common C++ functions and little helpers.
 * 
 * Author: Christian Koch
 * 
 * Copyright: This is licenced under the MIT licence. See "LICENCE"-file
 */
#pragma once

#include <array>
#include <stddef.h>
#include <cmath>

namespace common {
namespace math {

template<typename T> using Vec3 = std::array<T, 3>;
typedef Vec3<size_t> Index3;  


/**
 * @brief Wrap a value until it fits into a given range.
 *
 * For example, wrap angle into 0...360 degrees
 * or time into 0...24 hours.
 * 
 * The range is given by [min,max[  (i.e. min is included, max is exluded).
 * A value equal to max, is wrapped back to min.
 * 
 * @tparam T numeric type.
 * @param value The value to be wrapped
 * @param min The minimum possibel value (included).
 * @param max The maximum possible value (excluded). max > min must hold.
 * @return T the wrapped value
 */
template<typename T>
T wrap_value(T value, T min, T max)
{
    assert(min<max);
    T range = max - min;

    while (value >= max) {
        value -= range;
    }

    while (value < min) {
        value += range;
    }
    
    return value;
}


} // namespace math    
} // namespace common