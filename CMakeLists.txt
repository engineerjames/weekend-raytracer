cmake_minimum_required(VERSION 3.20)

project(weekend-raytracer CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(CTest)
enable_testing()

# TODO: Fix this nonsense.
set(Boost_DIR C:/Boost/tools/boost_install)
set(boost_headers_DIR C:/Boost/lib64-msvc-14.2/cmake/boost_headers-1.77.0)
set(boost_unit_test_framework_DIR C:/Boost/lib64-msvc-14.2/cmake/boost_unit_test_framework-1.77.0)

find_package(Boost COMPONENTS unit_test_framework REQUIRED CONFIG )

add_subdirectory(src)