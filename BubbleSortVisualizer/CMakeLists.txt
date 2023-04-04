cmake_minimum_required(VERSION 3.0)

project(BubbleSortVisualizer C)

# Set the source directory
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Set the path to the ConsoleEngine Makefile
set(CONSOLE_ENGINE_MAKEFILE "${CMAKE_CURRENT_SOURCE_DIR}/../ConsoleEngine/build/CmakeOutput/Makefile")




# Set the include directories
set(INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/../ConsoleEngine/src")

# Set the library directory
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../ConsoleEngine/build/CmakeOutput")



# Execute the ConsoleEngine Makefile before building the project
add_custom_command(
    OUTPUT ${LIB_DIR}/libConsoleEngine.a
    COMMAND make -C ${CONSOLE_ENGINE_MAKEFILE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../ConsoleEngine/build/CmakeOutput
)

# Link with the ConsoleEngine library
add_library(ConsoleEngine STATIC IMPORTED)
set_target_properties(ConsoleEngine PROPERTIES IMPORTED_LOCATION "${LIB_DIR}/libConsoleEngine.a")

# Add the include directories to the build
include_directories(${INCLUDE_DIRS})

# Get all .c files in the source directory
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.c")

# Create the executable and link with the ConsoleEngine library
add_executable(BubbleSortVisualizer ${SOURCES})
target_link_libraries(BubbleSortVisualizer ConsoleEngine)

