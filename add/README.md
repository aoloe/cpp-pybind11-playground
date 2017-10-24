# Add: the first example

This first example shows how to create a python module providing the `add()` function that returns the sum of the two integers given as a parameter.

This is the compile command that works for me:

```.sh
c++ -O3 -shared -fPIC -std=c++11 -I ~/src/pybind11/include -I /usr/include/python3.5 -L /usr/lib/python3 `python-config --cflags --ldflags` maths.cpp -o maths.so
```

As a result ou will get the python library `maths.so`.

You can now import the "maths" module in Python3. Start Python3 in the directory where the file is located and:

```.py
>>> import maths
>>> print(maths.add(1,2))
3
>>>
```

# Notes

the pybind11 documentation is suggesting the following:

  ```.sh
  c++ -O3 -shared -std=c++11 -I <path-to-pybind11>/include `python-config --cflags --ldflags` maths.cpp -o maths.so
  ```

but it fails for me.

First I need to tell the compiler to use Python3 (since Debian and many other Linux distributions still default to Python2):

  ```.sh
  c++ -O3 -shared -fPIC -std=c++11 -I ~/src/pybind11/include -I /usr/include/python3.5 -L /usr/lib/python3 `python-config --cflags --ldflags` maths.cpp -o maths.so
  ```

  (<https://docs.python.org/3/extending/embedding.html#compiling-and-linking-under-unix-like-systems>)

Then I need to add a `main()` function in the `.cpp` file.

Question: (how) can I compile a pure library without any main?

## Further steps

- have a look at <http://blog.conan.io/2016/04/12/Extending-python-with-C-or-C++-with-pybind11.html> for creating a plugin (instead of a module)
