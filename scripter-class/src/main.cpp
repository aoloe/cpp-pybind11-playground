#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

#include "foo.h"

namespace py = pybind11;
using namespace pybind11::literals;

void runFile(std::string fileName)
{
    py::scoped_interpreter guard{};
    
    Foo foo1, foo2;
    
    auto module = py::module::import("fooapi");
    
    auto locals = py::dict("foo_copy"_a=foo1,
                            "foo_ref"_a=py::cast(foo2, py::return_value_policy::reference)); // foo1 by value, foo2 by reference
    
    //py::eval_file(fileName, py::globals(), locals);
    
    //assert(foo1.bar == 1);
    //assert(foo2.bar == 5);
}

int main()
{
    runFile("../python/set-bar.py");
    runFile("../python/set-bar.py");
}
