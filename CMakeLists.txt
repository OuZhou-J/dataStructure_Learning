cmake_minimum_required(VERSION 3.22)
project (data_structure)

set(target "main")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stack)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/string)
add_executable(${target} main.cpp)

target_link_libraries(${target} useStack stringFunc)