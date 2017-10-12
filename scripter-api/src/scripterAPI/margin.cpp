#include <pybind11/pybind11.h>

#include "scripterAPI/margin.h"

namespace py = pybind11;

void init_MarginAPI(py::module &m) {
    py::class_<ScripterAPI::Margin>(m, "Margin")
        // .def(py::init<>())
        .def_property("top", &ScripterAPI::Margin::getTop, &ScripterAPI::Margin::setTop)
        .def_property("right", &ScripterAPI::Margin::getRight, &ScripterAPI::Margin::setRight)
        .def_property("bottom", &ScripterAPI::Margin::getBottom, &ScripterAPI::Margin::setBottom)
        .def_property("left", &ScripterAPI::Margin::getLeft, &ScripterAPI::Margin::setLeft)
        ;
}
