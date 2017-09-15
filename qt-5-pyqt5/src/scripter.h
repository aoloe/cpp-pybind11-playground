#ifndef SCRIPTER_H
#define SCRIPTER_H

#include <string>
#include <QString>

#undef slots // avoid conflicts between Python.h and Qt slots
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#define slots Q_SLOTS

namespace py = pybind11;

class Scripter
{
    public:
        Scripter();
        void runFile(std::string fileName);
    private:
        py::scoped_interpreter guard{}; // start the interpreter and keep it alive
};
#endif
