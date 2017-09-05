# Eval a python script that modifies a C++ object

- http://pybind11.readthedocs.io/en/latest/advanced/embedding.html
- https://github.com/pybind/pybind11/blob/master/tests/test_eval.cpp#L63

~~~.sh
$ mkdir build
$ cmake -Dpybind11_DIR=/home/ale/bin/pybind11 -DPYTHON_EXECUTABLE:FILEPATH=/usr/bin/python3 ..
$ make
$ ./scripting
~~~
