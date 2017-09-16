#include <pybind11/pybind11.h>
#include "foo.h"

namespace py = pybind11;

PYBIND11_MODULE(fooapi, m) {
    py::class_<Foo>(m, "Foo")
        .def(py::init<>())
        .def_readwrite("bar", &Foo::bar)
        ;
}
