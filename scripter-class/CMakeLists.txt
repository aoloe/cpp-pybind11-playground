CMAKE_MINIMUM_REQUIRED(VERSION 3.4)
PROJECT(scripting)

SET(PYBIND11_PYTHON_VERSION 3.4)

FIND_PACKAGE(pybind11 CONFIG)

ADD_EXECUTABLE(scripting
    src/main.cpp
    src/scripter.cpp
)
TARGET_LINK_LIBRARIES(scripting
    ${PYTHON_LIBRARIES}
    pybind11::embed
)

PROJECT(fooapi)
PYBIND11_ADD_MODULE(fooapi src/foo.cpp)
