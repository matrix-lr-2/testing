cmake_minimum_required(VERSION 3.12)

project(Test_matrix)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(matrix)

add_executable(test_matrix main.cpp)
target_link_libraries(test_matrix PUBLIC matrix)

add_subdirectory(test)