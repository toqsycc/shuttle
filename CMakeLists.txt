#
#
#
#
#
#
#

cmake_minimum_required(VERSION 3.22)

# Setting up compiler
include(./cmake/shuttle.cmake)

# Setting up project

set(PROJECT_NAME Shuttle)

if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE DEBUG)
endif()

if(NOT DEVICE)
set(DEVICE ATmega2560)
endif()

set(TARGET ${PROJECT_NAME}_${DEVICE}_${CMAKE_BUILD_TYPE} C CXX ASM)

include_directories(${PROJECT_SOURCE_DIR}/user)

set(PROJECT_SOURCES
	user/shuttle.cpp
)

#add_executable(${TARGET}.elf ${PROJECT_SOURCES})
