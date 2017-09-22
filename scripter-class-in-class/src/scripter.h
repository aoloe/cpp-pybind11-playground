#ifndef SCRIPTER_H
#define SCRIPTER_H
#include <string>

#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

namespace py = pybind11;

class Scripter
{
    public:
        void runFile(std::string fileName);
    private:
        py::scoped_interpreter guard{};
};
#endif
