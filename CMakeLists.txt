cmake_minimum_required(VERSION 3.10)

project(fenwick_trees)

# generic_1D rule
file(GLOB GENERIC_header "generic_1D/include/*")
file(GLOB GENERIC_sources "generic_1D/src/*.cpp")
add_executable(generic ${GENERIC_sources})

# non-generic target
file(GLOB NORMAL_header "normal_1D/include/*")
file(GLOB NORMAL_sources "normal_1D/src/*.cpp")
add_executable(non-generic ${NORMAL_sources})
