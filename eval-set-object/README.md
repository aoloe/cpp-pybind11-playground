# Evaluate a Python script that modifies a C++ object

Create two C++ objects `foo_1` and `foo_2` of type `Foo` and pass them to a Python script (defined as a string in the C++ code):

- the first object is passed by value,
- the second one by reference.

The Python script modifies both values and the C++ code then checks that the first object has not changed but the second has.

~~~.sh
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./scripting
~~~

The output from the Python script shows that the bar in `foo_copy` initially has the value `1`, but then gets the value `5`.

Outside of the script, back in the C++ code, the two asserts confirm that the bar in `foo_1` (passted by copy) still has the value `1` and the one in `foo_2` is now `5`.

## References

see http://pybind11.readthedocs.io/en/master/advanced/embedding.html
