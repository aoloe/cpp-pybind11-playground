cmake_minimum_required(VERSION 3.4)
project(scripting)

set(PYBIND11_PYTHON_VERSION 3.4)

FIND_PACKAGE(pybind11 CONFIG)

ADD_EXECUTABLE(scripting src/main.cpp)
TARGET_LINK_LIBRARIES(scripting
    ${PYTHON_LIBRARIES}
    pybind11::embed
)

project(fooapi)
pybind11_add_module(fooapi src/foo.cpp)
