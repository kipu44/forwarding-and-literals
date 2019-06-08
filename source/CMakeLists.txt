
cmake_minimum_required(VERSION 3.0)

set(CMAKE_VERBOSE_MAKEFILE OFF)

project(main)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror -Wextra -Wpedantic")

add_executable(${CMAKE_PROJECT_NAME} foo-bar.h indent.cpp indent.h main.cpp raii.h)
