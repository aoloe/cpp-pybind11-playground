#include <pybind11/pybind11.h>

#include "scripterAPI/document.h"

namespace py = pybind11;

void init_DocumentAPI(py::module &m) {
    py::class_<ScripterAPI::Document>(m, "Document")
        .def(py::init<>())
        .def("getPage", &ScripterAPI::Document::getPage)
        .def("addPage", &ScripterAPI::Document::addPage)
        .def_property_readonly("margin", &ScripterAPI::Document::getMargin)
        ;
}
