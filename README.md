# pybind11

## Getting pybind11

By default, the samples in this repositories use a pre-compiled version of pybind11.

You will have to first get pybind11, compile it, and install it:

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

Our [first example](add/) directly uses the compiler, all other examples will need a modern version of `cmake` being installed (pybind11 should have cmake 3.4)

## Sample projects

- [`add/`](add/): using a c++ module to add two numbers in Python
- [`add-cmake`](add-cmake/): the first example plus cmake
- [`classes/`](classes/): let Python use C++ classes
- [`eval-file/`](eval-file/): C++ evaluates a Python script in an external files that modifies the state of a C++ variable.
- [`eval-set-object/`](eval-set-object/): Create two objects of type `Foo` and pass them to a Python script (defined as a string in the C++ code)
- [`eval-set-object-module/`](eval-set-object-module/): Create a `.so` module for the `Foo` type, load it get the Python script to access it.
- [`eval-file-pyqt5/`](eval-file-pyqt5/): The C++ code runs an external Python script that shows a PyQt5 alert.
- ...

## Links

- and HN thread: <https://news.ycombinator.com/item?id=15095757>
- how to use cmake with pybind11 <https://github.com/pybind/pybind11/pull/1098>

## Notes

- pybind11 runs python code as if it was run in Python's `exec()` call. The visibility of the global and local variables works in the same way: <https://gist.github.com/dean0x7d/df5ce97e4a1a05be4d56d1378726ff92>

## alternatives

- [cppy](https://pypi.python.org/pypi/cppyy) is an automatic Python-C++ bindings generator designed for large scale programs in high performance computing that use modern C++.

## todo

document all directories:

- [x] add
- [x] add-cmake
- [ ] classes
- [ ] eval-file
- [ ] eval-set-object
- [ ] eval-set-object-module
- [ ] eval-file-pyqt5
- [ ] eval-file-pyqt5-set-value
- [ ] scripter-api
- [ ] scripter-class
- [ ] scripter-class-in-class
- [ ] scripting
- [ ] scripting-pyqt5
- [ ] qt5-pyqt5

open questions:

- [ ] how to pass sys.argv to the `QApplication()` in `eval-file-pyqt5/python/pyqt5.py`
