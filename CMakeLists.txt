cmake_minimum_required(VERSION 3.14)

project(weekend-raytracer CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(CTest)
enable_testing()

if (WIN32)
    set(Boost_DIR C:/Boost/tools/boost_install)
    set(boost_headers_DIR C:/Boost/lib64-msvc-14.3/cmake/boost_headers-1.80.0)
    set(boost_unit_test_framework_DIR C:/Boost/lib64-msvc-14.3/cmake/boost_unit_test_framework-1.80.0)
else()
    set( Boost_DIR /usr/lib/x86_64-linux-gnu/cmake/Boost-1.71.0/ )
endif()

find_package(Boost COMPONENTS unit_test_framework REQUIRED )

add_subdirectory(src)
add_subdirectory(src_original)
add_subdirectory(test)