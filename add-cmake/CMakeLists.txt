cmake_minimum_required(VERSION 2.8.12)
project(maths)

IF( NOT EXISTS "${PYBIND11_DIR}" )
    SET(PYBIND11_DIR ${PROJECT_SOURCE_DIR}"/pybind11")
ENDIF()

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

FIND_PACKAGE(Pybind11 REQUIRED)

SET(CMAKE_MODULE_PATH ${PYBIND11_DIR}/tools ${CMAKE_MODULE_PATH})
INCLUDE(${PYBIND11_DIR}/tools/pybind11Tools.cmake)

pybind11_add_module(maths src/maths.cpp)
