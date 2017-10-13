#include <pybind11/pybind11.h>

#include "scripterAPI/scripterAPI.h"

namespace py = pybind11;

void init_ScripterAPI(py::module &m) {
    py::class_<ScripterAPI::ScripterAPI>(m, "Sample")
        .def(py::init<>())
        .def_readwrite("a", &ScripterAPI::ScripterAPI::a)
        .def_readwrite("document", &ScripterAPI::ScripterAPI::documentAPI)
    ;
}

void init_DocumentAPI(py::module &);
void init_PageAPI(py::module &);
void init_MarginAPI(py::module &);

PYBIND11_MODULE(scripterapi, m) {
        m.doc() = "Python interface the Sample application";
        init_ScripterAPI(m);
        init_DocumentAPI(m);
        init_PageAPI(m);
        init_MarginAPI(m);
}
