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
	py::scoped_interpreter guard{}; // start the interpreter and keep it alive

	Foo foo1, foo2;

	auto module = py::module::import("foo_module");

	auto locals = py::dict("foo_copy"_a=foo1, "foo_ref"_a=&foo2, **module.attr("__dict__"));  // note the &
	py::exec(R"(
		print(foo_copy.bar);
		foo_copy.bar = 5;
		print(foo_copy.bar);
		foo_ref.bar = 5;
	)", py::globals(), locals);

	assert(foo1.bar == 1);
	assert(foo2.bar == 5);

}
