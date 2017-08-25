# Calling pybind11 from c++

A small c++ program with an API, that calls python that consumes the API.

~~~.sh
$ mkdir build
$ cmake -DPYBIND11_DIR=/home/ale/src/pybind11 -DPYTHON_EXECUTABLE:FILEPATH=/usr/bin/python3 ..
$ make
$ ./scripting
~~~

