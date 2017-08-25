# Add: the first example

- install `python3-cxx-dev`
- this is the command the documentation is suggesting:  

  ~~~.sh
  c++ -O3 -shared -std=c++11 -I <path-to-pybind11>/include `python-config --cflags --ldflags` maths.cpp -o maths.so
  ~~~

- using

  ~~~.sh
  c++ -O3 -fPIC -std=c++11 -I <path-to-pybind11>/include `python-config --cflags --ldflags` maths.cpp -o maths.so
  ~~~

  i get `undefined reference to `main'`
- so it gets:

  ~~~.sh
  c++ -O3 -fPIC -std=c++11 -I <path-to-pybind11>/include `python-config --cflags --ldflags` -c maths.cpp -o maths.so
  ~~~

  to compile without linking.  
  but then, in python i get `ImportError: maths.so: only ET_DYN and ET_EXEC can be loaded` because it's not linked.  
  we need a main, and drop the `-c`.
- the compilation is working, but when importing the module, python3 complains:

  ~~~
  ImportError: dynamic module does not define module export function (PyInit_maths)
  ~~~

  we were compiling with python2, but using python3. the `g++` finally is:

  ~~~.sh
  c++ -O3 -shared -fPIC -std=c++11 -I /home/ale/src/pybind11/include -I /usr/include/python3.5 -L /usr/lib/python3 `python-config --cflags --ldflags` maths.cpp -o maths.so
  ~~~

  (<https://docs.python.org/3/extending/embedding.html#compiling-and-linking-under-unix-like-systems>)

- yeah!

## Further steps

- have a look at <http://blog.conan.io/2016/04/12/Extending-python-with-C-or-C++-with-pybind11.html> for creating a plugin (instead of a module)
