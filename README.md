# pybind11 as a scripting engine

This tutorial explains in 14 steps how to use `pybind11` for creating a Python scripting engine for a Qt application.

It first explains how to create a module that can be imported in Python, continues by prosenting different aspects of running inside of a C++ (Qt) application a Python script that can access (and modify) the status of the main application.

Each step contains code that can be individually compiled, run, and – of course – modified.

You should probably go through each step in the order presented below, since the commands are (briefly) introduced only once.

## Getting pybind11

There are three ways for getting pybind11:

- _Embedding_ it in your project as a Git submodule.
- Installing pybind11 through your package manager (or downloading binaries that are installed in the system path).
  - In 2023, in Debian Testing you need to install `pybind11-dev` and `python3-pybind11`.
- Compiling pybind11 in a separate directory.


The samples in this repositories use a pre-compiled version of pybind11. If you're not getting pybind11 from your distribution repositories:

- get the code from github
- compile it:
  - `mkdir build && cd build`
  - `cmake -D CMAKE_INSTALL_PREFIX=/the/prefix/where/you/install/pybind11 -D PYBIND11_TEST=OFF ..`
  - `make install`

The pybind11 authors prefer adding pybind11 as a git sub-project: you can of course follow their instruction and adapt the `CMakeLists.txt` files in this repository.

## The development environment

You need:

- a development environment for C++ (g++ or clang; cmake, ...)
- the Python bindings (`libpython3-dev`, `python-cxx-dev`, ...)

Our [first example](add/) directly uses the compiler, all other examples will need a modern version of `cmake` being installed (pybind11 needs cmake 3.4)

## Sample projects

- [`add/`](add/): create a module providing a C++ `add` function that can be add two numbers.
- [`add-cmake`](add-cmake/): the first example with CMake (all further examples use CMake).
- [`classes/`](classes/): let Python use C++ classes.
- [`eval-file/`](eval-file/): C++ evaluates a Python script in an external files that modifies the state of a C++ variable.
- [`eval-set-object/`](eval-set-object/): Create two objects of type `Foo` and pass them by value or by reference to a Python script (defined as a string in the C++ code)
- [`eval-set-object-module/`](eval-set-object-module/): Create a `.so` module for the `Foo` type, load it in the Python interpreter and let the Python script access it.
- [`eval-file-pyqt5/`](eval-file-pyqt5/): The C++ code runs an external Python script that shows a PyQt5 alert.
- [`eval-file-pyqt5-set-value/`](eval-file-pyqt5-set-value/): Setting a C++ value from a PyQt5 input dialog.
- ...

## Links

- an HN thread: <https://news.ycombinator.com/item?id=15095757>
- how to use cmake with pybind11 <https://github.com/pybind/pybind11/pull/1098>

## Notes

- pybind11 runs python code as if it was run in Python's `exec()` call. The visibility of the global and local variables works in the same way: <https://gist.github.com/dean0x7d/df5ce97e4a1a05be4d56d1378726ff92>
- read https://github.com/GooFit/GooFit/blob/master/python/goofit/Variable.cpp as an example for...

## alternatives

- [cppy](https://pypi.python.org/pypi/cppyy) is an automatic Python-C++ bindings generator designed for large scale programs in high performance computing that use modern C++.

## todo

- [ ] adapt all `CMakeLists.txt` files to require Python 3.7. (`eval-set-object-module` does somehow require it)
- [ ] use pyside2 on top of pyqt5
- [ ] can python use the c++ qt widgets (add an entry to the menus, add keyboard shortcuts); can we have callbacks back to python code from the c++ app?
- [ ] in the qt5-pyqt example there is a "visibility" warning.
- [ ] Try to add a menu entry from pyqt5
- [ ] Try with PySide2

Document all directories:

- [x] add
- [x] add-cmake
- [x] classes
- [x] eval-file
- [x] eval-set-object
- [x] eval-set-object-module
- [x] eval-file-pyqt5
- [ ] eval-file-pyqt5-set-value
- [ ] scripter-api
- [ ] scripter-class
- [ ] scripter-class-in-class
- [ ] scripting
- [ ] scripting-pyqt5
- [ ] qt5-pyqt5

open questions:

- [ ] how to pass sys.argv to the `QApplication()` in `eval-file-pyqt5/python/pyqt5.py`
