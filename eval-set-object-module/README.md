# C++ creates and loads a module and runs a Python script that uses the module to modify its own state

The C++ `foo.h` and `foo.cpp` provide the `fooapi` Python module (a `.so` shared object defining the `Foo` class with a `bar` member variable (an integer initialized to `1`).

The `main.cpp` program includes the `foo.h` library and imports the `fooapi` into the Python interpreter.

It calls the usual Python script with two variables, one by copy and one by reference.

~~~.sh
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./scripting
~~~
