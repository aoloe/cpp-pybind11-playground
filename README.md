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

## Sample projects

- [`add/`](add/): the first example.
- [`add-cmake`](add-cmake/): the first example with cmake
- ...

## Links

- and HN thread: <https://news.ycombinator.com/item?id=15095757>
- how to use cmake with pybind11 <https://github.com/pybind/pybind11/pull/1098>

## Notes

- pybind11 runs python code as if it was run in Python's `exec()` call. The visibility of the global and local variables works in the same way: <https://gist.github.com/dean0x7d/df5ce97e4a1a05be4d56d1378726ff92>

## alternatives

- [cppy](https://pypi.python.org/pypi/cppyy) is an automatic Python-C++ bindings generator designed for large scale programs in high performance computing that use modern C++.
