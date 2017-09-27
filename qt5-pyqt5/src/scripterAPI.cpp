#include <pybind11/pybind11.h>
#include "scripterAPI.h"

namespace py = pybind11;

PYBIND11_MODULE(sampleapi, m) {
    m.doc() = "pybind11 scripter api";

    py::class_<ScripterAPI> foo(m, "Sample");
    foo
        .def(py::init<>())
        .def_readwrite("bar", &ScripterAPI::bar);
}

