cmake_minimum_required(VERSION 3.10)

project(DesignPatterns)

# Set C++ standard (change to your desired version)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)
# Set the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(
    /usr/lib/boost_1_83_0
)
link_directories(
    /usr/lib/boost_1_83_0/stage/lib
)
add_subdirectory("00_SolidDesignPrinciples")
add_subdirectory("01_Builder")
add_subdirectory("02_Factory")