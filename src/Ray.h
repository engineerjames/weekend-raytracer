#ifndef RAY_H
#define RAY_H

#include "Color.h"
#include "Vector.h"

#include <cmath>

class Ray
{
public:
  Point3f getOrigin() const { return origin_; }
  Vector3f getDirection() const { return direction_; }

  Point3f at(float t) const { return origin_ + t * direction_; }

  Color getColor() const
  {
    Vector3f unit_direction = direction_.toUnit();
    auto t = (0.5 * unit_direction.y() + 1.0);

    Color rayColor = std::lerp() // TODO: use this
                         (1.0 - t) *
                         Color{1, 1, 1} +
                     t * Color{0.5, 0.7, 1.0};
  }

private:
  Point3f origin_;
  Vector3f direction_;
};

#endif