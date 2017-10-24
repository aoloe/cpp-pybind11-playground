# C++ launches a Python script that loads a shared library module and sets a c++ variable

- Use the C++ foo.[h|cpp] files to create a `.so` shared object (module)
- Load the module from the C++ main program Python.
- Call the Python script from the C++ code and pass one variable by value and the other by reference.
- The Python script modifies the variable.
- The c++ code checks that the values has been modified

~~~.sh
$ mkdir build
$ cd build
$ cmake -Dpybind11_DIR=/home/ale/bin/pybind11/share/cmake/pybind11 ..
$ make
$ ./scripting
~~~
