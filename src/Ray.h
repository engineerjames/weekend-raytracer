#ifndef RAY_H
#define RAY_H

#include "Point.h"
#include "Vector.h"

class Ray
{
public:
    Point3f getOrigin() const { return origin_; }
    Vector3f getDirection() const { return direction_; }

    Point3f at(float t) const {
        return origin_ + t * direction_;
    }

private:
    Point3f origin_;
    Vector3f direction_;
};

#endif