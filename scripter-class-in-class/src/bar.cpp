#include <pybind11/pybind11.h>
#include "bar.h"

namespace py = pybind11;

PYBIND11_MODULE(barapi, m) {
    py::class_<Bar>(m, "Bar")
        .def(py::init<>())
        .def_readwrite("value", &Bar::value)
        ;
}

