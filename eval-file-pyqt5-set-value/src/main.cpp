#include <iostream>
#include <pybind11/embed.h>

namespace py = pybind11;

int main()
{
	// http://pybind11.readthedocs.io/en/latest/advanced/embedding.html#getting-started
	py::scoped_interpreter guard{}; // start the interpreter and keep it alive

	auto local = py::dict();
	local["y"] = py::int_(43);

	int val_out;
	local["set_the_answer"] = py::cpp_function([&](int value) { val_out = value; });

    py::eval_file("../input-number.py", py::globals(), local);

	std::cout << "value set by the python script: " << val_out << std::endl;
}
