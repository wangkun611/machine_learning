cmake_minimum_required(VERSION 2.8.8)

SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

if (CMAKE_VERSION VERSION_LESS 3.0)
    PROJECT(machine_learning CXX)
else()
    cmake_policy(SET CMP0048 NEW)
    PROJECT(machine_learning VERSION "${LIB_VERSION_STRING}" LANGUAGES CXX)
endif()

option(CMAKE_BUILD_COVERAGE "build for coverage" OFF)

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
if (CMAKE_BUILD_COVERAGE)
  include(CMakeModules/CodeCoverage.cmake)
  append_coverage_compiler_flags()
  setup_target_for_coverage_lcov(
      NAME coverage
      EXECUTABLE ctest -j 2
      EXCLUDE "gtest/*" "CMake*" "*_unittest.cc" "/Library/Developer/*")

endif()

set(GOOGLETEST_VERSION 1.10.0)
# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(gtest/googletest)
add_subdirectory(least_square)

