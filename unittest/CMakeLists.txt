cmake_minimum_required(VERSION 2.8.8)

project(pcl_test)

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -std=c++14")

# Make test executable
set(TEST_SOURCES main.cc number_theory_test.cc)
add_executable(main.out ${TEST_SOURCES})
target_link_libraries(main.out Catch)
