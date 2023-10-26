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
   * @brief Generate equally spaced points in a 3D grid
   * 
   * Points are aligned with the three axis defining the space (e.g. x, y, z axes in a cartesian coordinate system).
   * 
   * @tparam T numerical type to use for point cooridnates.
   */
  template <typename T>
  class GridPointGenerator
  {
  public:

    /**
     * @brief Construct a new Grid Point Generator object
     * 
     * @param from starting point
     * @param to final point
     * @param step step size for each dimensaion
     */
    GridPointGenerator(const Vec3<T>& from, const Vec3<T>& to, const Vec3<T>& step)
    : m_from(from), m_to(to), m_step(step)
    {
      calculate_size();
      reset();
    }

    /**
     * @brief Reset internal states.
     * 
     * Most notably, the internal state keeps track of the current point for the next() method.
     * Resetting means, next() will start again with the first point.
     */
    void reset() {
      m_current_point = m_from;
      m_end_reached = false;
    }

    /**
     * @brief Get the size in each dimension
     * 
     * @return Index3 size
     */
    Index3 get_size() {
      return m_size;
    }

    /**
     * @brief Get the total number of elements.
     * 
     * @return size_t 
     */
    size_t number_of_elements() {
      return m_size[0] * m_size[1] * m_size[2];
    }

    /**
     * @brief Get the point corresponding to a certain index
     * 
     * @param idx Index of the desired point
     * @return Vec3<T> point at index idx
     */
    Vec3<T> at(Index3 idx) {
      return {m_from[X] + idx[X] * m_step[X],
        m_from[Y] + idx[Y] * m_step[Y],
        m_from[Z] + idx[Z] * m_step[Z] };
    }

    /**
     * @brief Calculate and return the next point.
     *
     * Calculate and return the next point. The points are calculated in the order Z-Y-X. When the end is reached, false is returned.
     *
     * An internal state is used to keep track of the current point. Use reset() to reset internal states.
     *
     * @param out_point
     * @return true Valid point
     * @return false End of grid reached
     */
    bool next( Vec3<T>* out_point ) {
      if (m_end_reached) {
        return false;
      }
      
      *out_point = m_current_point;

      // calculate next point
      if (advance_point_checked(&m_current_point, Z) == false) {
        if (advance_point_checked(&m_current_point, Y) == false) {
          if (advance_point_checked(&m_current_point, X) == false) {
            m_end_reached = true;
          }
        }
      }

      return true;
    }

    /**
     * @brief Return all points as once in anested vector.
     * 
     * This might require a lot of memory!
     * 
     * @return std::vector<std::vector<std::vector<Vec3<T>>>> All points.
     */
    std::vector<std::vector<std::vector<Vec3<T>>>> as_vector ()
    {
      std::vector<std::vector<std::vector<Vec3<T>>>> points;
      
      for (size_t x=0; x<m_size[X]; x++) {
        points.push_back(std::vector<std::vector<Vec3<T>>>());
        for (size_t y=0; y<m_size[Y]; y++) {
          points[x].push_back(std::vector<Vec3<T>>());
          for (size_t z=0; z<m_size[Z]; z++) {
            points[x][y].push_back(at({x,y,z}));
          }
        }
      }

      return points;  
    }

  private:
  
    static const size_t X=0;
    static const size_t Y=1;
    static const size_t Z=2;

    Vec3<T> m_from;
    Vec3<T> m_to;
    Vec3<T> m_step;
    Index3 m_size;

    Vec3<T> m_current_point;
    bool m_end_reached;

    void calculate_size()
    {
      for (size_t dim=0; dim<3; dim++) {
        m_size[dim] = (m_to[dim] - m_from[dim]) / m_step[dim] + 1;
      }
    }

    /**
     * @brief Advance a point in one dimension.
     * 
     * When the end is reached in the dimension, the dimension is reset to the start value. Also, false is returned.
     * 
     * @param point the current point
     * @param dim dimension, must be 0, 1 or 2.
     * @return true Ok
     * @return false End for dimension was reached
     */
    bool advance_point_checked(Vec3<T> *point, size_t dim)
    {
      (*point)[dim] += m_step[dim];
      if ((*point)[dim] > m_to[dim]) {
        (*point)[dim] = m_from[dim];
        return false;
      }
      return true;
    }
    
  };      

} // namespace math    
} // namespace common