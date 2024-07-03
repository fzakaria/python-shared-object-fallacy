#include <Python.h>
#include <dlfcn.h>
#include "libfoo/foo.h"

static PyObject* py_bar(PyObject* self, PyObject* args) {
    bar();
    Py_RETURN_NONE;
}

static PyMethodDef Methods[] = {
    {"bar", py_bar, METH_VARARGS, "Call bar from libfoo"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef ModuleDef = {
    PyModuleDef_HEAD_INIT,
    "a.ext",
    "Python interface for the libfoo library",
    -1,
    Methods
};

PyMODINIT_FUNC PyInit_ext(void) {
    return PyModule_Create(&ModuleDef);
}
