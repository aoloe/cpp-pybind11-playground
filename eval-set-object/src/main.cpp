#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

namespace py = pybind11;

// for the _a string litteral
// http://pybind11.readthedocs.io/en/stable/basics.html#keyword-arguments
using namespace pybind11::literals;

struct Foo { int bar = 1; };


PYBIND11_EMBEDDED_MODULE(foo_module, m) {
	py::class_<Foo>(m, "Foo").def_readwrite("bar", &Foo::bar);
}

int main()
{
	py::scoped_interpreter guard{};

	Foo foo_1, foo_2;

	auto module = py::module::import("foo_module");

	auto locals = py::dict(
        "foo_copy"_a=foo_1, // by value
        "foo_ref"_a=py::cast(foo_2, // by reference
            py::return_value_policy::reference),
        **module.attr("__dict__"));
	py::exec(R"(
		print(foo_copy.bar);
		foo_copy.bar = 5;
		print(foo_copy.bar);
		foo_ref.bar = 5;
	)", py::globals(), locals);

	assert(foo_1.bar == 1);
	assert(foo_2.bar == 5);

}
