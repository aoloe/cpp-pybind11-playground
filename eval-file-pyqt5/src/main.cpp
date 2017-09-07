#include <iostream>
#include <pybind11/embed.h>

namespace py = pybind11;

int main()
{
	// http://pybind11.readthedocs.io/en/latest/advanced/embedding.html#getting-started
	py::scoped_interpreter guard{}; // start the interpreter and keep it alive

    py::object scope = py::module::import("__main__").attr("__dict__");
    py::eval_file("../pyqt5.py", scope);
}
