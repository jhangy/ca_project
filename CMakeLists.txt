cmake_minimum_required(VERSION 2.6)
project(main)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
SET(SRCS ./cpp/path_generator.cpp ./cpp/predictor.cpp ./cpp/simulator.cpp main.cpp)

include_directories(SRCS PUBLIC ./hpp)

ADD_EXECUTABLE (main ${SRCS})

target_compile_options (main PRIVATE -std=c++11)