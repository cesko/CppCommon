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

namespace common {
namespace math {

    template<typename T> using Vec3 = std::array<T, 3>;
    typedef Vec3<size_t> Index3;
  

} // namespace math    
} // namespace common