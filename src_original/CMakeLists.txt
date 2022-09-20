add_executable(main_original
    main.cpp
    )

target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(main PRIVATE cxx_std_20)

if (WIN32)
  target_compile_options(main PRIVATE /W3)
endif()