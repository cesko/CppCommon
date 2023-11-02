#include <gtest/gtest.h>

#include "math/math_common.hpp"

using namespace common;
using namespace math;


TEST(Math_Common, wrap_value) {
  const float ALLOWED_ERROR = 1e-4;

  // Double 
  EXPECT_NEAR(wrap_value<double>(0.0, 0.0, 1.0), 0.0, ALLOWED_ERROR);
  EXPECT_NEAR(wrap_value<double>(1.0, 0.0, 1.0), 0.0, ALLOWED_ERROR);
  EXPECT_NEAR(wrap_value<double>(0.5, 0.0, 1.0), 0.5, ALLOWED_ERROR);
  EXPECT_NEAR(wrap_value<double>(1.25, 0.0, 1.0), 0.25, ALLOWED_ERROR);
  EXPECT_NEAR(wrap_value<double>(-0.25, 0.0, 1.0), 0.75, ALLOWED_ERROR);
  EXPECT_NEAR(wrap_value<double>(100.1, 0.0, 1.0), 0.1, ALLOWED_ERROR);

  // Float 
  EXPECT_NEAR(wrap_value<float>(0.0f, 0.0f, 1.0f), 0.0f, ALLOWED_ERROR);
  EXPECT_NEAR(wrap_value<float>(1.0f, 0.0f, 1.0f), 0.0f, ALLOWED_ERROR);
  EXPECT_NEAR(wrap_value<float>(0.5f, 0.0f, 1.0f), 0.5f, ALLOWED_ERROR);
  EXPECT_NEAR(wrap_value<float>(1.25f, 0.0f, 1.0f), 0.25f, ALLOWED_ERROR);
  EXPECT_NEAR(wrap_value<float>(-0.25f, 0.0f, 1.0f), 0.75f, ALLOWED_ERROR);
  EXPECT_NEAR(wrap_value<float>(100.1f, 0.0f, 1.0f), 0.1f, ALLOWED_ERROR);

  // Integer
  EXPECT_EQ(wrap_value<int>(0, 0, 12), 0);
  EXPECT_EQ(wrap_value<int>(12, 0, 12), 0);
  EXPECT_EQ(wrap_value<int>(5, 0, 12), 5);
  EXPECT_EQ(wrap_value<int>(15, 0, 12), 3);
  EXPECT_EQ(wrap_value<int>(-2, 0, 12), 10);
  EXPECT_EQ(wrap_value<int>(25, 0, 12), 1);

  // Angles
  EXPECT_DOUBLE_EQ(wrap_value(  90.0, -180.0, 180.0),   90.0);
  EXPECT_DOUBLE_EQ(wrap_value( 180.0, -180.0, 180.0), -180.0);
  EXPECT_DOUBLE_EQ(wrap_value( 360.0, -180.0, 180.0),    0.0);
  EXPECT_DOUBLE_EQ(wrap_value( -90.0, -180.0, 180.0),  -90.0);
  EXPECT_DOUBLE_EQ(wrap_value(-360.0, -180.0, 180.0),    0.0);
  EXPECT_DOUBLE_EQ(wrap_value(-377.5, -180.0, 180.0),  -17.5);

  // Invalid input
  // TODO

}
