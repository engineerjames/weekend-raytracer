#ifndef RAY_H
#define RAY_H

#include "Color.h"
#include "Vector.h"

#include <cmath>

class Ray
{
public:
  [[nodiscard]] Point3f getOrigin() const noexcept { return origin_; }
  [[nodiscard]] Vector3f getDirection() const noexcept { return direction_; }

  [[nodiscard]] Point3f at(float t) const noexcept { return origin_ + t * direction_; }

  [[nodiscard]] Color getColor() const noexcept
  {
    Vector3f unit_direction = direction_.toUnit();
    auto t = (0.5 * unit_direction.y() + 1.0);

    Color white {1, 1, 1};
    Color blue {0.5, 0.7, 1.0};

    Color rayColor = (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
  }

private:
  Point3f origin_;
  Vector3f direction_;
};

#endif