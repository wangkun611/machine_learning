cmake_minimum_required(VERSION 2.8.8)

project(machine_learning)

if (CMAKE_VERSION VERSION_LESS "3.1")
  add_definitions(-std=c++14)
else()
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  if(NOT CYGWIN)
    set(CMAKE_CXX_EXTENSIONS OFF)
  endif()
endif()

enable_testing()

set(GOOGLETEST_VERSION 1.10.0)
# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(gtest/googletest)
add_subdirectory(least_square)
