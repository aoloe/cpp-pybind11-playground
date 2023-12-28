# Call twice PySide6 from a Python script running inside of c++ code

As reported in <https://github.com/pybind/pybind11/issues/1702>, there was an issue when importing multiple times PyQt5 from Python scripts running in a c++ application.

This seems to be solved with PySide6 and the latest pybind11
