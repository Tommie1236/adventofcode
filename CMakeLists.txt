cmake_minimum_required(VERSION 3.5)

project(AoC-Default)
project(DefaultProjectName)

# Allow overriding the project name via a command-line option
if(DEFINED EXTERNAL_PROJECT_NAME)
    set(PROJECT_NAME ${EXTERNAL_PROJECT_NAME} CACHE INTERNAL "Project name override")
endif()

add_subdirectory(src)