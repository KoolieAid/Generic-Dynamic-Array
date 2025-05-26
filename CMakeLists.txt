cmake_minimum_required(VERSION 3.10...4.0)

project(DynamicArray LANGUAGES C)

add_library(dynarr STATIC src/DynamicArray.c)
target_include_directories(dynarr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(test)
