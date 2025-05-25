cmake_minimum_required(VERSION 3.10)

project(dynarr LANGUAGES C)

add_library(dynarr STATIC DynamicArray.c)
