#include <iostream>
#include <pybind11/embed.h>

namespace py = pybind11;

int main()
{
	// http://pybind11.readthedocs.io/en/latest/advanced/embedding.html#getting-started
	py::scoped_interpreter guard{}; // start the interpreter and keep it alive

    // inject the y variable into the python script
	auto local = py::dict();
	local["y"] = py::int_(43);

    // inject the set_the_answer() funciton into the python script.
    // set_the_answer() modifies the c++ variable val_out
	int val_out{7};
	local["set_the_answer"] = py::cpp_function([&](int value) { val_out = value; });

	std::cout << "the c++ value value before calling the python script: " << val_out << std::endl;

    py::object scope = py::module::import("__main__").attr("__dict__");
    py::eval_file("set-the-y.py", scope, local);

	std::cout << "the c++ value after calling the python script: " << val_out << std::endl;
}
