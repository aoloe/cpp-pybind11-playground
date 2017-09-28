#include <pybind11/pybind11.h>

#include "scripterAPI/document.h"

namespace py = pybind11;

void init_DocumentAPI(py::module &m) {
    py::class_<ScripterAPI::Document>(m, "Document")
        .def(py::init<>())
        .def_readwrite("a", &ScripterAPI::Document::a)
        ;
}
