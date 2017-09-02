#include <pybind11/eval.h>
namespace py = pybind11;

int main()
{
    py::object scope = py::module::import("__main__").attr("__dict__");
    py::eval_file("../helloworld.py", scope);
}
