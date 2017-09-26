#include <pybind11/pybind11.h>

#include "scripterAPI/document.h"

namespace py = pybind11;

PYBIND11_MODULE(documentapi, m) {
    py::class_<ScripterAPI::Document>(m, "Document")
        .def(py::init<>())
        .def_readwrite("document", &ScripterAPI::Document::a)
        ;
}
