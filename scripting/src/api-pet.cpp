#include <string>
#include <pybind11/pybind11.h>

#include "pet.h"

int main()
{
}

namespace py = pybind11;

PYBIND11_MODULE(petapi, m) {
    m.doc() = "pybind11 class example plugin"; // optional module docstring

    py::class_<Dog>(m, "Dog")
    .def(py::init<const std::string &>())
    .def("setName", &Dog::setName, "Setting the dog's name")
    .def("getName", &Dog::getName), "Getting the dog's name";

    py::class_<Cat>(m, "Cat")
    .def(py::init<const std::string &>())
    .def_property("name", &Cat::getName, &Cat::setName);
}
