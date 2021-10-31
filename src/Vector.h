#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <concepts>
#include <type_traits>

template<std::floating_point T>
class Vector3
{
    public:
        constexpr Vector3()
        : data_{0, 0, 0}
        { }

        Vector3(T x, T y, T z)
        : data_{x, y, z}
        { }

        T x() const { return data_[0]; }
        T y() const { return data_[1]; }
        T z() const { return data_[2]; }

        T& x() { return data_[0]; }
        T& y() { return data_[1]; }
        T& z() { return data_[2]; }

        Vector3& operator+=(const Vector3& rhs)
        {
            x() += rhs.x();
            y() += rhs.y();
            z() += rhs.z();

            return *this;
        }

        Vector3& operator*=(T rhs)
        {
            x() *= rhs;
            y() *= rhs;
            z() *= rhs;

            return *this;
        }

        Vector3& operator/=(T rhs)
        {
            x() *= rhs;
            y() *= rhs;
            z() *= rhs;

            return *this;
        }

        T length() const
        {
            return std::sqrt(x() * x() +
                             y() * y() +
                             z() * z());
        }

    private:
        T data_[3];
};

#endif // VECTOR3_H