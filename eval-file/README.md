# Eval a python script that modifies a C++ object

From the C++ code we run a Python script that modifies the state of a C++ variable by calling a C++ function.

In the C++ program we define a `local` list that contains the variable and the function passed to the Python file when evaluating it.

~~~.sh
$ mkdir build
$ cd build
$ cmake -Dpybind11_DIR=~/bin/pybind11/share/cmake/pybind11 ..
$ make
$ ./scripting
~~~

## References

- http://pybind11.readthedocs.io/en/latest/advanced/embedding.html
- https://github.com/pybind/pybind11/blob/master/tests/test_eval.cpp#L63
