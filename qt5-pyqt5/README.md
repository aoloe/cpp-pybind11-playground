# Encapsulate the scripter in a class

~~~.sh
$ mkdir build
$ cmake -DCMAKE_BUILD_TYPE=Debug ..
$ make
$ ./sample
~~~

## Notes

- running twice `run()`, produces a crash.
- If you prefer you can symlink pybind11 directory and replace the `find_package` with `add_subdirectory` in `CMakeLists.txt`
