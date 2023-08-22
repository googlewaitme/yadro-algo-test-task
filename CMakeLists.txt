cmake_minimum_required(VERSION 3.10)

project(task)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(lib/googletest)
