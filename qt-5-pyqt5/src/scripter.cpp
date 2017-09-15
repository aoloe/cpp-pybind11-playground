#include "scripter.h"
#include "scripterAPI.h"

using namespace pybind11::literals; // for the ""_a

Scripter::Scripter()
{
	auto module = py::module::import("sampleapi");
}

void Scripter::runFile(std::string fileName)
{
	ScripterAPI foo1, foo2;


	auto locals = py::dict("foo_copy"_a=foo1, "foo_ref"_a=py::cast(foo2, py::return_value_policy::reference)); // foo1 by value, foo2 by reference

    py::eval_file(fileName, py::globals(), locals);

	assert(foo1.bar == 1);
	assert(foo2.bar == 5);
}
