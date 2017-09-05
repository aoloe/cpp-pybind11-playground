# pybind11

## Getting pybind11

- get the code from github
- (install `python3-pytest`)
- compile it as explained the documentation
  - `mkdir build && cd build`
  - `cmake -D CMAKE_INSTALL_PREFIX=/the/prefix/where/you/install/pybind11 ..`
  - `make install`

## Sample projects

- [`add/`](add/): the first example.
- [`add-cmake`](add-cmake/): the first example with cmake

## Links

- and HN thread: <https://news.ycombinator.com/item?id=15095757>

## alternatives

- [cppy](https://pypi.python.org/pypi/cppyy) is an automatic Python-C++ bindings generator designed for large scale programs in high performance computing that use modern C++.
