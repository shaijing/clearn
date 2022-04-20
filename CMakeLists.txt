cmake_minimum_required(VERSION 3.21)

#form 1：
#project(<PROJECT-NAME> [<language-name>...])
#form 2：
#project(<PROJECT-NAME>
#[VERSION <major>[.<minor>[.<patch>[.<tweak>]=]=]]
#[DESCRIPTION <project-description-string>]
#[HOMEPAGE_URL <url-string>]
#[LANGUAGES <language-name>...])

project(clearn C)
set(CMAKE_C_STANDARD 99)

# ##############################################################################
# Build
# ##############################################################################

# Add header file include directories
include_directories(./include)

file(GLOB_RECURSE
        SRC_SUB ${PROJECT_SOURCE_DIR}/src/learn/*.c
        ${PROJECT_SOURCE_DIR}/src/practice/*.c
        ${PROJECT_SOURCE_DIR}/src/adt/*.c
        ${PROJECT_SOURCE_DIR}/src/arithmetic/*.c
        ${PROJECT_SOURCE_DIR}/src/exam/*.c
        ${PROJECT_SOURCE_DIR}/src/example/*.c
        ${PROJECT_SOURCE_DIR}/src/test/*.c)
set(ALL_SRC ${SRC_TOP} ${SRC_SUB})
message("ALL_SRC: ${ALL_SRC}")
add_executable(cpplearn main.c main.h ${ALL_SRC})