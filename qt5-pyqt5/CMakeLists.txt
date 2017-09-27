CMAKE_MINIMUM_REQUIRED(VERSION 3.4)

PROJECT(sample)

SET(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

set(PYBIND11_PYTHON_VERSION 3.4)

FIND_PACKAGE(pybind11 CONFIG)

ADD_DEFINITIONS(-DSCRIPTS_DIRECTORY="${CMAKE_SOURCE_DIR}")

ADD_EXECUTABLE(sample
    src/main.cpp
    src/sample.cpp
    src/mainwindow.cpp
    src/scripter.cpp
)

target_link_libraries(sample
    Qt5::Widgets
    ${PYTHON_LIBRARIES}
    pybind11::embed
)

project(sampleapi)
pybind11_add_module(sampleapi src/scripterAPI.cpp)
