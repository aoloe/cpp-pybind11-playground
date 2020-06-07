# pybind11 and cmake

This second example shows how to use cmake to compile the [add example](../add).

All further examples, will use cmake.

The `pybind11_DIR` passed to the cmake commands tells the compiler where to find the library.

This sample uses a "pre-compiled" version of pybind11. If you prefer using git submodules, please refer to the official demo project that fetches pybind11 as a git submodule: <https://github.com/pybind/cmake_example>.

## The `CMakeLists.txt` file

```cmake
cmake_minimum_required(VERSION 3.4)
project(maths)

set(PYBIND11_PYTHON_VERSION 3.4)

find_package(pybind11 CONFIG)

pybind11_add_module(maths
    src/maths.cpp
)
```

## Compiling and running

```.sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

If pybind11 is not installed in a standard path, you'll need to tell cmake where it is installed by providing `pybind11_DIR` :

```.sh
$ cmake -Dpybind11_DIR=~/bin/pybind11/share/cmake/pybind11 ..
```

You will now have a file with a name similar to `maths.cpython-37m-x86_64-linux-gnu.so` which you can import in python3:


```sh
$ python3
>>> import maths
>>> maths.add(1, 2)
3
```
