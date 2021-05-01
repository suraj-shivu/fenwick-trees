cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(fenwick_trees)

# header files
include_directories(include)

# generic_1D rule
file(GLOB GENERIC_sources "generic_1D/src/*.cpp")
add_executable(generic ${GENERIC_sources})

# non-generic target
file(GLOB NORMAL_sources "normal_1D/src/*.cpp")
add_executable(non-generic ${NORMAL_sources})
