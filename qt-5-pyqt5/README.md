# qt application calling a python script access the c++ API of the application

- Create a `.so` module.
- Call the Python script from the c++ code and pass a variable per reference.
- The Python script loads the module and modify the variable.
- The c++ code checks that the values has been modified

~~~.sh
$ mkdir build
$ cmake -Dpybind11_DIR=/home/ale/bin/pybind11/share/cmake/pybind11 -DCMAKE_BUILD_TYPE=Debug ..
$ make
$ ./sample
~~~
