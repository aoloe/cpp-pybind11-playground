#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

#include "scripter.h"
#include "foo.h"

namespace py = pybind11;

using namespace pybind11::literals;

void run()
{
    Scripter scripter1;
    scripter1.runFile("../python/set-bar.py");
}

int main()
{
    run();
    run();
}
