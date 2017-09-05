cmake_minimum_required(VERSION 3.0)
# cmake_minimum_required(VERSION 3.4) # probably 3.4 is needed for mac
project(scripting)

MESSAGE( STATUS "CMAKE_MODULE_PATH: " ${CMAKE_MODULE_PATH} )

FIND_PACKAGE(pybind11 CONFIG)

ADD_EXECUTABLE(scripting src/main.cpp)
TARGET_LINK_LIBRARIES(scripting pybind11::embed)
