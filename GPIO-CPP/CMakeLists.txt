cmake_minimum_required(VERSION 3.22)

project(
    gpio
    VERSION 3.0
    LANGUAGES CXX
)

set(CMAKE_GENERATOR XCODE)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Werror -Wextra -std=c++11)
endif()
# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

add_executable(gpio src/main.cpp src/funcs.cpp)

add_library(funcslib src/funcs.cpp)