cmake_minimum_required(VERSION 3.21)

# ##############################################################################
# Normal Configure
# ##############################################################################

project(clearn C)
set(CMAKE_C_STANDARD 99)

# ##############################################################################
# Build
# ##############################################################################

# Add header file include directories
include_directories(include)
include_directories(lib)

file(GLOB_RECURSE SRC ${PROJECT_SOURCE_DIR}/src/*.c)


add_executable(cpplearn  ${SRC})