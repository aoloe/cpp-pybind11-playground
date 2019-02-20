#include <pybind11/embed.h>

namespace py = pybind11;

int main()
{
	py::scoped_interpreter guard{};

    py::object scope = py::module::import("__main__").attr("__dict__");
    py::eval_file("pyqt5.py", scope);
}
