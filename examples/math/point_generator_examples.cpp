#include "math/point_generator.hpp"

#include <iostream>

using namespace common;

void grid_point_generator()
{
  std::cout << "Generate Points on a Grid:" << std::endl;
  

  math::Vec3<float> from({0.0f, 0.0f, 0.0f});
  math::Vec3<float> to({0.0f, 0.2f, 2.0f});
  math::Vec3<float> step({1.0f, 0.1f, 1.0f});
  math::GridPointGenerator<float> grid(from, to, step);

  auto size = grid.get_size();
  std::cout << "Size: " << size[0] << " x " << size[1] << " x " << size[2]
    << " = " << grid.number_of_elements() << " elements " << std::endl;

  std::cout << "\nGet all points in nested vectors:" << std::endl;
  auto points = grid.as_vector();
  size_t counter = 0;
  for (auto vy : points) {
    for (auto vz : vy) {
      for (auto point : vz) {
        std::cout << counter << ": (" << point[0] << ", " << point[1] << ", " << point[2] << ")" 
          << std::endl;
        counter++;
      }
    }
  }

  std::cout << "\nIterate all points via next():" << std::endl;
  math::Vec3<float> point;
  counter = 0;
  while (grid.next(&point)) {
    std::cout << counter << ": (" << point[0] << ", " << point[1] << ", " << point[2] << ")" 
      << std::endl;
    counter ++;
  }
}

int main()
{
  grid_point_generator();
}