cmake_minimum_required(VERSION 3.4)
project(maths)

set(PYBIND11_PYTHON_VERSION 3.4)

find_package(pybind11 CONFIG)

include_directories(src)

pybind11_add_module(maths
    src/maths.cpp
)
