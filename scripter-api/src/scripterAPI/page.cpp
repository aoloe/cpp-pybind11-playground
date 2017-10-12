#include <pybind11/pybind11.h>

#include "scripterAPI/page.h"

namespace py = pybind11;

void init_PageAPI(py::module &m) {
    py::class_<ScripterAPI::Page>(m, "Page")
        // .def(py::init<>())
        .def_property("margin", &ScripterAPI::Page::getMargin, &ScripterAPI::Page::setMargin)
        ;
}
