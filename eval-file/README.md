# Eval a python script that modifies a C++ object

This example shows how to create a C++ program that _runs_ a Python script that has access to variables and functions defined in the C++ program itself.

The first step is to include the `pybind11`'s `embed.h` library:

```cpp
#include <pybind11/embed.h>
```

We then need to load the Python interpreter:

```cpp
py::scoped_interpreter guard{};
```

We do not directly use it and it will be automatically destroyed when it goes out of scope.

In the _local_ environment variable, we create a variable and a function that will be injected in the the Python script's environment:

```cpp
auto local = py::dict();
local["y"] = ...;
local["set_the_answer"] = ...;
```

The `scope` variable _contains_ the scope of the main module of our interpreter:

```cpp
py::object scope = py::module::import("__main__").attr("__dict__");
```

We can finally _evaluate_ our Python script:

```cpp
py::eval_file("set-the-y.py", scope, local);
```

What does the script do?

```py
set_the_answer(y - 1)
```

It simply calls the `set_the_answer()` function we have defined by passing the _injected_ variable `y` decremented by one.

The final effect is that the `val_out` variable we have defined in our C++ code will now have a value of 42 (`y - 1`) instead of the original `7`.

You can try it with:

~~~.sh
$ mkdir build
$ cd build
$ cmake
$ make
$ ./scripting
~~~

With the `configure_file` command, `CMakeLists.txt` copies the Python script into the build directory.

You can modify the Python Script in your build directory and see that the value printed by the `scripting` program will change accordingly.

## Todo

- What does it mean that we cannot have two concurrent interpreters (as mentioned in the pybind11 documentation)?

## References

- http://pybind11.readthedocs.io/en/latest/advanced/embedding.html
- https://github.com/pybind/pybind11/blob/master/tests/test_eval.cpp#L63
