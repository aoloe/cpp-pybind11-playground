# Providing an API for manipuling a document

A Scripter engine providing Python scripting to a C++ Sample application. The the scripting main goal are modifications to the current document in the C++ application.

- `src/sample/` contains the data structures for the document used in the C++ application.  

  ```
  sample
    .document
      .margin
        .top
        .right
        .bottom
        .left
      .page[]
        .margin
          ...
   ```
- `src/scripterAPI/` contains the interface for the Python module. the "Sample" document is not directly exposed to the Python code.
- the `scripterapi` Python module is created by `src/scripterAPI/scripterAPI.cpp` by collecting the module definitions for each `scripterAPI` class.
- the memory management for the document respects the following constraints:
  - the c++ application might or not have an open document.
  - if there is an open document, it's shared with the API.
  - the API can modify the document.
  - while the script is running, the C++ application is not allowed to modify the document(s).
  - (eventually, trough the API it should be possible to change the current document to any other open document)
  - through the API, it should be possible to open documents / create new documents.
  - (eventually, the document will be left open when the script is finished)

~~~.sh
$ mkdir build
$ cmake -Dpybind11_DIR=/home/ale/bin/pybind11/share/cmake/pybind11 ..
$ make
$ ./scripting
~~~

## notes

- if we ever want to check how it works with `unique_ptr`s, this is a good article on how to add a `unique_ptr` as a private member in a class: <https://katyscode.wordpress.com/2012/10/04/c11-using-stdunique_ptr-as-a-class-member-initialization-move-semantics-and-custom-deleters/>
