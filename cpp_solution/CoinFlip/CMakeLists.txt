# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MyCppProject VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files
include_directories(include)

# Add the executable target
add_executable(MyCppProject src/main.cpp)

# If you have multiple source files, list them all: add_executable(MyCppProject
# src/main.cpp src/other_file.cpp)
