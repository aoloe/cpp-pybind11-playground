# Providing an API for manipuling a document

Demoing how to provide an API that let's a Python script manipulate a document strucuture in the c++ application.

- The application is called "Sample".
- Its API for Python is called "ScripterAPI"
- The `Document` data structure (and its "sub" elements) contains the data of the c++ appplication.
- From Python you import a module called "Sample" and access the document as `Sample.document`

~~~.sh
$ mkdir build
$ cmake -Dpybind11_DIR=/home/ale/bin/pybind11/share/cmake/pybind11 ..
$ make
$ ./scripting
~~~
