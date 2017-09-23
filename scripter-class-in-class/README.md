# adding multiple classes to a python module

the python code can set `foo.bar.value`

~~~.sh
$ mkdir build
$ cmake -Dpybind11_DIR=/home/ale/bin/pybind11/share/cmake/pybind11 ..
$ make
$ ./scripting
~~~

# Notes

Pybind11 tries to set the visibilty for all symbols as hidden. In the `CMakeLists.txt` We need to set

    set(CMAKE_CXX_VISIBILITY_PRESET hidden)

because of the guard in the `script.h` file
