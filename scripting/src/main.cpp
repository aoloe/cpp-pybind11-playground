#include <Python.h>
#include "pet.h"

int main()
{
    setenv("PYTHONPATH", ".", 1);

    wchar_t *programName = Py_DecodeLocale("test-script", NULL);
    Py_SetProgramName(programName);
    Py_Initialize();

    PyRun_SimpleString("from time import time,ctime\n"
                       "print('Today is', ctime(time()))\n"
                       "import petapi\n"
                       "a = petapi.Cat('Fitz')\n"
                       "print(a.name)\n");
    Py_Finalize();
    /*
        if (Py_FinalizeEx() < 0) { // new in 3.6
            exit(120);
        }
    */
    PyMem_RawFree(programName);
}
