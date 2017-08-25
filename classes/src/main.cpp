#include <string>
#include <pybind11/pybind11.h>

class Dog {
public:
    Dog(const std::string &name) : name(name) {}
    void setName(const std::string &n) {name = n;}
    const std::string getName() const {return name;}
private:
    std::string name;
};

class Cat {
public:
    Cat(const std::string &name) : name(name) {}
    void setName(const std::string &n) {name = n;}
    const std::string getName() const {return name;}
private:
    std::string name;
};

int main()
{
}

namespace py = pybind11;

PYBIND11_MODULE(pet, m) {
    m.doc() = "pybind11 class example plugin"; // optional module docstring

    py::class_<Dog>(m, "Dog")
    .def(py::init<const std::string &>())
    .def("setName", &Dog::setName, "Setting the dog's name")
    .def("getName", &Dog::getName), "Getting the dog's name";

    py::class_<Cat>(m, "Cat")
    .def(py::init<const std::string &>())
    .def_property("name", &Cat::getName, &Cat::setName);
}
