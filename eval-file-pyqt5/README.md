# Eval a python script that launches a PyQt5 dialog

The C++ code runs an external Python script that shows a PyQt5 alert.

Warning: we need to create a `QApplication` before being able to use a `QWidget`

~~~.sh
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./scripting
~~~

Todo:

- [ ] in the Python script use a function `ask_question()` instead of the class.
