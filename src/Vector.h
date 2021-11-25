#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <concepts>
#include <iostream>
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

        Vector3& operator/=(T rhs) // TODO: Re-evaluate pass-by-value
        {
            x() *= rhs;
            y() *= rhs;
            z() *= rhs;

            return *this;
        }

        Vector3<T> toUnit() const
        {
            (*this)/this->length();
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

// Utility functions
template<std::floating_point T>
std::ostream& operator<<(std::ostream& out, const Vector3<T>& vector)
{
    return out << vector.x() << ", " << vector.y() << ", " << vector.z();
}

template<std::floating_point T>
bool operator==(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
    return  lhs.x() == rhs.x() &&
            lhs.y() == rhs.y() &&
            lhs.z() == rhs.z();
}

template<std::floating_point T>
bool operator!=(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
    return !(lhs==rhs);
}

template<std::floating_point T>
Vector3<T> operator+(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return Vector3{ v1.x() + v2.x(),
                    v1.y() + v2.y(),
                    v1.z() + v2.z()};
}

template<std::floating_point T>
Vector3<T> operator-(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return Vector3{ v1.x() - v2.x(),
                    v1.y() - v2.y(),
                    v1.z() - v2.z()};
}

template<std::floating_point T>
Vector3<T> operator*(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return Vector3{ v1.x() * v2.x(),
                    v1.y() * v2.y(),
                    v1.z() * v2.z()};
}

template<std::floating_point T, std::floating_point U>
Vector3<T> operator*(const Vector3<T>& v1, U scalar)
{
    // The cast is needed to ensure if U is of type 'double'
    // and T is of type 'float', that we return Vector3<float>
    // vs. Vector3<double> as would normally happen via promotion
    return Vector3{
        static_cast<T>(v1.x() * scalar),
        static_cast<T>(v1.y() * scalar),
        static_cast<T>(v1.z() * scalar)
    };
}

template<std::floating_point T, std::floating_point U>
Vector3<T> operator*(U scalar, const Vector3<T>& v1 )
{
    return v1*scalar;
}

template<std::floating_point T, std::floating_point U>
Vector3<T> operator/(Vector3<T> v1, U scalar)
{
    return (1.0/scalar) * v1;
}

template<std::floating_point T>
T dot(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return (v1.x() * v2.x() +
            v1.y() * v2.y() +
            v1.z() * v2.z());
}

template<std::floating_point T>
Vector3<T> cross(const Vector3<T>& v1, const Vector3<T>& v2)
{
    return Vector3(
        v1.y() * v2.z() - v1.z() * v2.y(),
        v1.z() * v2.x() - v1.x() * v2.z(),
        v1.x() * v2.y() - v1.y() * v2.x()
    );
}

#endif // VECTOR3_H