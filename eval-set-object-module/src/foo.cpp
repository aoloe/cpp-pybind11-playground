#include <pybind11/pybind11.h>
#include "foo.h"

namespace py = pybind11;

PYBIND11_MODULE(fooapi, m) {
    m.doc() = "pybind11 foo api";

    py::class_<Foo> foo(m, "Foo");
    foo
        .def(py::init<>())
        .def_readwrite("bar", &Foo::bar);
}
