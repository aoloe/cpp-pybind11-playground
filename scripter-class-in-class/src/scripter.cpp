#include "scripter.h"
#include "foo.h"
#include "bar.h"

using namespace pybind11::literals; // for the ""_a

void Scripter::runFile(std::string fileName)
{
	Foo foo;

    std::cout << foo.bar.value << std::endl;

	auto module = py::module::import("fooapi");

    // auto locals = py::dict("foo"_a=foo); // foo by value
	auto locals = py::dict("foo"_a=py::cast(foo, py::return_value_policy::reference)); // foo by reference

    py::eval_file(fileName, py::globals(), locals);

    std::cout << foo.bar.value << std::endl;
}
