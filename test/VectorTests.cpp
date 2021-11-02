#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "Vector.h"

BOOST_AUTO_TEST_CASE( CAN_ADD_TWO_VECTORS )
{
    Vector3<float> v1{0.1f, 0.1f, 0.1f};
    Vector3<float> v2{0.2f, 0.2f, 0.2f};

    float expectedValue = 0.1f + 0.2f;

    Vector3<float> actualResult = v1 + v2;
    Vector3<float> expectedResult {expectedValue, expectedValue, expectedValue};

    BOOST_ASSERT(actualResult == expectedResult);
}

BOOST_AUTO_TEST_CASE( CAN_SUBTRACT_TWO_VECTORS )
{
    Vector3<float> v1{0.1f, 0.1f, 0.1f};
    Vector3<float> v2{0.2f, 0.2f, 0.2f};

    float expectedValue = 0.1f - 0.2f;

    Vector3<float> actualResult = v1 - v2;
    Vector3<float> expectedResult {expectedValue, expectedValue, expectedValue};

    BOOST_ASSERT(actualResult == expectedResult);
}

BOOST_AUTO_TEST_CASE( CAN_MULTIPLY_TWO_VECTORS )
{
    Vector3<float> v1{0.1f, 0.1f, 0.1f};
    Vector3<float> v2{0.2f, 0.2f, 0.2f};

    float expectedValue = 0.1f * 0.2f;

    Vector3<float> actualResult = v1 * v2;
    Vector3<float> expectedResult {expectedValue, expectedValue, expectedValue};

    BOOST_ASSERT(actualResult == expectedResult);
}

BOOST_AUTO_TEST_CASE( CAN_SCALE_VECTORS )
{
    Vector3<float> v1{0.1f, 0.1f, 0.1f};
    float scalar = 5.0f;

    float expectedValue = 0.1f * 5.0f;

    Vector3<float> actualResult = v1 * scalar;
    Vector3<float> actualResult2 = scalar * v1;
    Vector3<float> expectedResult {expectedValue, expectedValue, expectedValue};

    BOOST_ASSERT(actualResult == expectedResult);
    BOOST_ASSERT(actualResult2 == expectedResult);
}

BOOST_AUTO_TEST_CASE( CAN_SCALE_VECTORS_MIXED )
{
    Vector3<float> v1{0.1f, 0.1f, 0.1f};
    double scalar = 5.0;


    float expectedValue = 0.1f * 5.0f;

    Vector3<float> actualResult = v1 * scalar;
    Vector3<float> actualResult2 = scalar * v1;
    Vector3<float> expectedResult {expectedValue, expectedValue, expectedValue};

    BOOST_ASSERT(actualResult == expectedResult);
    BOOST_ASSERT(actualResult2 == expectedResult);
}

BOOST_AUTO_TEST_CASE( CAN_CALCULATE_DOT )
{
    Vector3<float> v1{0.1f, 0.0f, 0.0f};
    Vector3<float> v2{0.1f, 0.0f, 0.0f};

    float actualResult = dot(v1, v2);
    float actualResult2 = dot(v2, v1);
    float expectedResult = 0.1f * 0.1f;

    BOOST_ASSERT(actualResult == expectedResult);
    BOOST_ASSERT(actualResult2 == expectedResult);
}

BOOST_AUTO_TEST_CASE( CAN_CALCULATE_CROSS )
{
    Vector3<float> v1{0.1f, 0.1f, 0.1f};
    Vector3<float> v2{0.25f, 0.15f, 0.35f};

    Vector3<float> actualResult = cross(v1, v2);
    Vector3<float> expectedResult {0.02f, -0.01f, -0.01f};

    BOOST_ASSERT(actualResult == expectedResult);
}