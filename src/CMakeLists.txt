cmake_minimum_required(VERSION 2.8.6)

project(Practice)

include(${CMAKE_HOME_DIRECTORY}/cmake/platform.cmake)
include(${CMAKE_HOME_DIRECTORY}/cmake/compiler.cmake)
include(${CMAKE_HOME_DIRECTORY}/cmake/base.cmake)
include(${CMAKE_HOME_DIRECTORY}/cmake/common.cmake)

#省略zero_check
set(CMAKE_SUPPRESS_REGENERATION true)

option(BUILD_DATASTRUCTURE "build datastructure" TRUE)
option(BUILD_FRAMEWORKS "build frameworks" TRUE)

add_subdirectory(${CMAKE_HOME_DIRECTORY}/datastructure)