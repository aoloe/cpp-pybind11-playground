#include <pybind11/pybind11.h>

int add(int i, int j)
{
    return i + j;
}

int main()
{
}

namespace py = pybind11;

PYBIND11_MODULE(maths, m) {
        m.doc() = "pybind11 example plugin"; // optional module docstring

        m.def("add", &add, "A function which adds two numbers");
}
