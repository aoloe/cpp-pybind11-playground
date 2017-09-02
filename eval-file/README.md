# Eval a python script that modifies a C++ object

https://github.com/pybind/pybind11/blob/master/tests/test_eval.cpp#L63

~~~.sh
$ mkdir build
$ cmake -DPYBIND11_DIR=/home/ale/src/pybind11 -DPYTHON_EXECUTABLE:FILEPATH=/usr/bin/python3 ..
$ make
$ ./scripting
~~~
