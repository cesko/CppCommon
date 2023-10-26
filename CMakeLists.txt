cmake_minimum_required(VERSION 3.14)

project(cppcommon)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies
include_directories(include)

# Build Library
# add_library(foo STATIC src/Foo.cpp)

# Build Examples
add_executable(point_generator_examples examples/math/point_generator_examples.cpp)
#target_link_libraries(foo_demo foo)

# Unit Tests
add_subdirectory(test)
