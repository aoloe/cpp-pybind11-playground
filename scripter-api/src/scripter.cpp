#include <memory>
#include "scripter.h"
#include "scripterAPI/scripterAPI.h"
#include "sample/document.h"

using namespace pybind11::literals; // for the ""_a

void Scripter::runFile(std::string fileName)
{
    // Sample::Document document;
    //Sample::Margin saMargin;
    auto document = std::make_unique<Sample::Document>();

    ScripterAPI::ScripterAPI scripterAPI;
    scripterAPI.setDocument(std::move(document));


    auto module = py::module::import("scripterapi");

    auto locals = py::dict("Sample"_a=py::cast(scripterAPI, py::return_value_policy::reference));

    py::eval_file(fileName, py::globals(), locals);

    document = scripterAPI.getDocument();

    // assert(scripter.bar == 5);
}
