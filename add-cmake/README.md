# pybind11 and cmake

My first tries at getting `pybind11` to work for me. I share the notes, but do take them with a grain of salt!

- There is an official demo project that fetches pybind11 as a git submodule: <https://github.com/pybind/cmake_example>.  
  It probably works as is, but it does not fit my needs. Go through the official project first.
- Inspired by a few `Findpybind11.cmake` files that i've found on Github, i could hack together a `CMakeLists.txt` that works for my setup:
  - By default it looks for a `pybind11/` directory in the main project directory,
  - But you can pass a cusomt path in the `cmake` command

~~~.sh
$ mkdir build
$ cmake -DPYBIND11_DIR=/home/ale/src/pybind11 -DPYTHON_EXECUTABLE:FILEPATH=/usr/bin/python3 ..
$ make
$ python3
>>> import maths
>>> maths.add(1,2)
3
~~~
