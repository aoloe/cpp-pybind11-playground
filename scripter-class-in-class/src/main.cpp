#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

#include "scripter.h"

int main() {
    Scripter scripter;
    scripter.runFile("../python/set-bar.py");
}

