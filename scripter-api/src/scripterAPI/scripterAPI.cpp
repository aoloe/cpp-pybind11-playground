#include <pybind11/pybind11.h>

#include "scripterAPI/scripterAPI.h"

namespace py = pybind11;

PYBIND11_MODULE(scripterapi, m) {
    py::class_<ScripterAPI::ScripterAPI>(m, "Sample")
        .def(py::init<>())
        .def_readwrite("a", &ScripterAPI::ScripterAPI::a)
        .def_readwrite("document", &ScripterAPI::ScripterAPI::documentAPI)
        ;
}
