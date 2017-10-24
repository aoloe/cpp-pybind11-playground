# Eval a python script that launches a PyQt5 dialog

The C++ code runs an external Python script that shows a PyQt5 alert.

~~~.sh
$ mkdir build
$ cd build
$ cmake -Dpybind11_DIR=/home/ale/bin/pybind11/share/cmake/pybind11
$ make
$ ./scripting
~~~
