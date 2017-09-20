#include "scripter.h"
#include "scripterAPI.h"

using namespace pybind11::literals; // for the ""_a

void Scripter::runFile(std::string fileName)
{
	ScripterAPI api;

	auto module = py::module::import("sampleapi");

	auto locals = py::dict("Sample"_a=py::cast(api, py::return_value_policy::reference));

    py::eval_file(fileName, py::globals(), locals);

	assert(api.bar == 5);
}
