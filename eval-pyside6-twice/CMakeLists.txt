cmake_minimum_required(VERSION 3.4)
project(scripting)

set(PYBIND11_PYTHON_VERSION 3.11)

find_package(pybind11 CONFIG)

add_executable(scripting
    src/main.cpp
)
target_link_libraries(scripting
    pybind11::embed
)
