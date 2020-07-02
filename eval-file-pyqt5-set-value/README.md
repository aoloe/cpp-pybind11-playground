# Setting a C++ value from a PyQt5 input dialog

The C++ program defines a `set_the_answer` lambda that can receive the new value and passes it as `local` to the `input-number.py` script.

The Python script creates an (PyQt) application that is showing an input dialog. If the _Ok_ button is pressed, the `set_the_answer()` function passes the value to the C++ code.

One big warning: the `set_the_answer()` function is not visisble inside of `get_the_value()`: `pybind11` is passing the `set_the_answer()` as a local to the _eval_ (exec, in reality) Python context: we need to explicitely pass the outer local context to the `get_the_value()`, and  visible inside of it.  
(I've been told that this is becaue Python executes the code as if it was in a class environment...)

~~~.sh
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./scripting
~~~
