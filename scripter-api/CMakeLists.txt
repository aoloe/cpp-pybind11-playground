cmake_minimum_required(VERSION 3.4)
project(scripting VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

set(PYBIND11_PYTHON_VERSION 3.4)

find_package(pybind11 CONFIG)

include_directories(src)

add_executable(scripting
    src/main.cpp
    src/scripter.cpp
)
target_link_libraries(scripting
    pybind11::embed
)

PYBIND11_ADD_MODULE(scripterapi
    src/scripterAPI/scripterAPI.cpp
    src/scripterAPI/document.cpp
    src/scripterAPI/margin.cpp
)
