#include <memory>
#include "scripter.h"
#include "scripterAPI/scripterAPI.h"
#include "sample/document.h"

using namespace pybind11::literals; // for the ""_a

void Scripter::runFile(std::string fileName)
{
    // Sample::Document document;
    //Sample::Margin saMargin;

    ScripterAPI::ScripterAPI scripterAPI;
    scripterAPI.setDocument(document);


    auto module = py::module::import("scripterapi");

    auto locals = py::dict("Sample"_a=py::cast(scripterAPI, py::return_value_policy::reference));

    py::eval_file(fileName, py::globals(), locals);

    // document = scripterAPI.getDocument();

    // assert(scripter.bar == 5);
}
