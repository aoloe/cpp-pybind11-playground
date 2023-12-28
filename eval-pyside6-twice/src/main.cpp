#include <pybind11/embed.h>

namespace py = pybind11;

int main()
{
    {
        py::scoped_interpreter guard{};
        auto scope = py::globals();

        py::exec(R"(
            from PySide6.QtWidgets import QApplication
            print("first")
            )", scope
        );
    }
    {
        py::scoped_interpreter guard{};
        auto scope = py::globals();

        py::exec(R"(
            from PySide6.QtWidgets import QApplication
            print("second")
            )", scope
        );
    }
}
