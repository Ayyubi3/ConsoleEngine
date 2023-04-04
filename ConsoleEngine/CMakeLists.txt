cmake_minimum_required(VERSION 3.0)

project(ConsoleEngine C)

# Set the source directory
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Get all .c files in the source directory
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.c")

# Create the static library
add_library(ConsoleEngine STATIC ${SOURCES})

