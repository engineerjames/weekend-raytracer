add_executable(vector-tests VectorTests.cpp)
target_link_libraries(vector-tests PRIVATE Boost::unit_test_framework)
target_compile_features(vector-tests PRIVATE cxx_std_20)
target_include_directories(vector-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)

add_test( NAME vector-tests
          COMMAND $<TARGET_FILE:vector-tests>)