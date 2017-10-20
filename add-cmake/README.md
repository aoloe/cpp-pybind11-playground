# pybind11 and cmake

Adding `cmake` to avoid the complex `g++` call in the [add example](../add).

Like all examples in this repository we're not binding `pybind11` as a git submodule but compile it separately in `~/bin`

There is an official demo project that fetches pybind11 as a git submodule: <https://github.com/pybind/cmake_example>.

~~~.sh
$ mkdir build
$ cd build
$ cmake -Dpybind11_DIR=~/bin/pybind11/share/cmake/pybind11 ..
$ make
$ python3
>>> import maths
>>> maths.add(1,2)
3
~~~
