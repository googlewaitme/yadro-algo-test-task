cmake_minimum_required(VERSION 3.10)

project(task)

file(GLOB SOURCES src/*cpp)

add_executable(task ${SOURCES})
