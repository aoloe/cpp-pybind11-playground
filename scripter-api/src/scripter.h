#ifndef SCRIPTER_H
#define SCRIPTER_H
#include <string>

#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

#include "sample/document.h"

namespace py = pybind11;

class Scripter
{
    public:
        Scripter(Sample::Document* document) :
            document{document} {};
        void runFile(std::string fileName);
    private:
        Sample::Document* document;

        py::scoped_interpreter guard{};
};
#endif
