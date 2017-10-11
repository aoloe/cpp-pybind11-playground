#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

#include "sample/document.h"
// #include "sample/margin.h"
// 
#include "scripter.h"

namespace py = pybind11;

int main()
{
    Sample::Document document;

    Scripter scripter{&document};
    std::cout << "c++ document top " << document.margin.top << std::endl;
    scripter.runFile("../python/set-bar.py");
    std::cout << "c++ document top " << document.margin.top << std::endl;
    // std::cout << "document page 1 top" document.page.at(0).margin.top << std::endl;
}

