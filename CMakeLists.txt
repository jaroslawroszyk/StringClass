cmake_minimum_required(VERSION 3.20.2)
project(String CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter")

find_package(GTest REQUIRED)
find_package(fmt CONFIG REQUIRED)

set(LOG_LEVEL_TRACE 0)
set(LOG_LEVEL_DEBUG 1)
set(LOG_LEVEL_INFO 2)
add_compile_definitions(LOG_LEVEL LOG_LEVEL_TRACE)

add_subdirectory(String)
add_subdirectory(executable)