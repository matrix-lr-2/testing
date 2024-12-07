cmake_minimum_required(VERSION 3.12)

project(Test_matrix)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(matrix)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(googletest)

add_executable(test_matrix
        source/constructors_test.cpp
        source/index_assigment_operator_test.cpp
        source/output_test.cpp
        source/comparison_test.cpp
        source/arithmetic_test.cpp
        source/math_methods_test.cpp
)

target_link_libraries(test_matrix PUBLIC matrix GTest::gtest_main)