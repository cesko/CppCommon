#include <gtest/gtest.h>

#include "math/point_generator.hpp"

using namespace common;

TEST(Math_PointGenerator, basic_operation) {
  math::GridPointGenerator<double> grid({0.0, 0.0, 0.0}, {2.0, 2.0, 2.0}, {1.0, 1.0, 1.0});

  EXPECT_EQ(grid.get_size()[0], 3);
  EXPECT_EQ(grid.get_size()[1], 3);
  EXPECT_EQ(grid.get_size()[2], 3);
  
  EXPECT_EQ(grid.number_of_elements(), 27);


  math::Vec3<double> point;
  EXPECT_TRUE(grid.next(&point));
  EXPECT_EQ(point[0], 0.0);
  EXPECT_EQ(point[1], 0.0);
  EXPECT_EQ(point[2], 0.0);

  EXPECT_TRUE(grid.next(&point));
  EXPECT_EQ(point[0], 0.0);
  EXPECT_EQ(point[1], 0.0);
  EXPECT_EQ(point[2], 1.0);

  EXPECT_TRUE(grid.next(&point));
  EXPECT_EQ(point[0], 0.0);
  EXPECT_EQ(point[1], 0.0);
  EXPECT_EQ(point[2], 2.0);

  EXPECT_TRUE(grid.next(&point));
  EXPECT_EQ(point[0], 0.0);
  EXPECT_EQ(point[1], 1.0);
  EXPECT_EQ(point[2], 0.0);

  for(size_t i=4; i<27; i++) {
    EXPECT_TRUE(grid.next(&point));
  }

  EXPECT_EQ(point[0], 2.0);
  EXPECT_EQ(point[1], 2.0);
  EXPECT_EQ(point[2], 2.0);

  EXPECT_FALSE(grid.next(&point)); 
}

TEST(Math_PointGenerator, correct_sizes) {

  { // all dimensions 1
    math::GridPointGenerator<double> grid({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0});

    EXPECT_EQ(grid.get_size()[0], 1);
    EXPECT_EQ(grid.get_size()[1], 1);
    EXPECT_EQ(grid.get_size()[2], 1);
    
    EXPECT_EQ(grid.number_of_elements(), 1);
  }

  { // mixed dimensions
    math::GridPointGenerator<double> grid({0.0, 0.0, 0.0}, {5.0, 4.0, 4.2}, {2.0, 0.1, 1.0});

    EXPECT_EQ(grid.get_size()[0], 3);
    EXPECT_EQ(grid.get_size()[1], 41);
    EXPECT_EQ(grid.get_size()[2], 5);
    
    EXPECT_EQ(grid.number_of_elements(), 3*41*5);
  }  

  { // mixed dimensions
    math::GridPointGenerator<double> grid({0.0, 0.0, 0.0}, {1.0, 0.9, .8}, {2.0, 1.0, 0.2});

    EXPECT_EQ(grid.get_size()[0], 1);
    EXPECT_EQ(grid.get_size()[1], 1);
    EXPECT_EQ(grid.get_size()[2], 5);
    
    EXPECT_EQ(grid.number_of_elements(), 5);

    math::Vec3<double> point;
    for(size_t i=0; i<5; i++) {
      EXPECT_TRUE(grid.next(&point));
    }
    EXPECT_FALSE(grid.next(&point));

    auto vec = grid.as_vector();

    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0].size(), 1);
    EXPECT_EQ(vec[0][0].size(), 5);
  }

  { // negative values dimensions
    math::GridPointGenerator<double> grid({-1.0, -.1, -0.01}, {1.0, .1, .01}, {1.0, 0.1, 0.01});

    EXPECT_EQ(grid.get_size()[0], 3);
    EXPECT_EQ(grid.get_size()[1], 3);
    EXPECT_EQ(grid.get_size()[2], 3);
    
    EXPECT_EQ(grid.number_of_elements(), 27);
  }  


}
