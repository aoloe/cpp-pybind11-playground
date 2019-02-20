cmake_minimum_required(VERSION 3.4)
project(scripting)

set(PYBIND11_PYTHON_VERSION 3.7)

find_package(pybind11 CONFIG)

add_executable(scripting
    src/foo.cpp
    src/main.cpp
)
target_link_libraries(scripting
    pybind11::embed
)

pybind11_add_module(fooapi
    src/foo.cpp
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/python/set-bar.py
    ${CMAKE_CURRENT_BINARY_DIR}
    COPYONLY
)
