add_executable(main
    main.cpp
    Color.h
    PpmImage.h
    Ray.h
    Size.h
    Point.h
    Vector.h
    )

target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(main PRIVATE cxx_std_20)