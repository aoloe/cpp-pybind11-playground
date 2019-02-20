#include <iostream>
#include <pybind11/embed.h>

namespace py = pybind11;

class Dog
{
    public:
        void setName(std::string n) { name = n; }
        std::string getName() { return name; }
    private:
        std::string name;
};

int main()
{
    py::scoped_interpreter guard{};

    auto local = py::dict();

    int val_out;
    local["set_the_answer"] = py::cpp_function([&](int value) { val_out = value; });

    py::eval_file("input-number.py", py::globals(), local);

    std::cout << "value set by the python script: " << val_out << std::endl;
}
