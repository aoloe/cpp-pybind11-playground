# Add: the first example

This first example shows how to program in C++ a python module providing an `add()` function.

When imported in Pyhton, `add(a, b)` returns the sum of the two integers given as a parameter.

A very simple C++ library provides a function that returns the sum of two integer numbers:


```cpp
#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int i, int j)
{
    return i + j;
}

PYBIND11_MODULE(maths, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
}
```

The `PYBIND11_MODULE` macro creates a `maths` module:

- it first sets the documentation string for the module, then
- defines:
  - a Python function called `add`,
  - that will call the C++ `add` function passed as a reference,
  - and finally defines a documentation string for the `add` function.

If everything is setup _correctly_, you can compile the `maths.cpp` file with:

```sh
c++ -O3 -shared -fPIC `python-config --cflags --ldflags` src/maths.cpp -o maths.so
```

- If you're compiler does not default to (at least) C++ 11, you will need `-std=c++11`
- If you have a _local_ version of `pybind11` you will need  `-fPIC -I ~/src/pybind11/include`
- If your system does not default to Python 3, `-I /usr/include/python3.7 -L /usr/lib/python3`

As a result you will get the python library `maths.so`.

You can now import the "maths" module in Python3. Start Python3 in the directory where the `.so` file is located and:

```.py
>>> import maths
>>> print(maths.add(1,2))
3
>>>
```

You can also see the documentation with

```.py
>>> import maths
>>> help(maths)
Help on module maths:

NAME
    maths - pybind11 example plugin

FUNCTIONS
    add(...) method of builtins.PyCapsule instance
        add(arg0: int, arg1: int) -> int

        A function which adds two numbers

FILE
    /home/ale/src/cpp-pybind11-playground/add/maths.so
```

## Notes

My full g++ command is:

```
g++ -O3 -shared -fPIC -std=c++11 -I ~/src/pybind11/include -I /usr/include/python3.7 -L /usr/lib/python3 `python-config --cflags --ldflags` src/maths.cpp -o maths.so
```

## Further steps

- have a look at <http://blog.conan.io/2016/04/12/Extending-python-with-C-or-C++-with-pybind11.html> for creating a plugin (instead of a module)
