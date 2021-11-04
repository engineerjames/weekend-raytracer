#ifndef RAY_H
#define RAY_H

#include "Point.h"
#include "Vector.h"

class Ray
{
public:
    Point3<float> getOrigin() const { return origin_; }
    Vector3<float> getDirection() const { return direction_; }

    Point3<float> at(float t) const {
        return Point3<float>{}; // return origin_ + t * direction_; // TODO: Add vector operations for Point as well
    }

private:
    Point3<float> origin_;
    Vector3<float> direction_;
};

#endif