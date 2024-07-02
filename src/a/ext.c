#include <Python.h>
#include <dlfcn.h>
#include "libfoo/foo.h"

void (*buzz)();

static PyObject* py_buzz(PyObject* self, PyObject* args) {
    if (!handle) {
        PyErr_SetString(PyExc_ImportError, dlerror());
        return NULL;
    }

    *(void **)(&buzz) = dlsym(handle, "buzz");
    if (!buzz) {
        PyErr_SetString(PyExc_ImportError, dlerror());
        return NULL;
    }

    buzz();
    dlclose(handle);
    Py_RETURN_NONE;
}

static PyMethodDef PackageAMethods[] = {
    {"buzz", py_buzz, METH_VARARGS, "Call buzz from libfoo 1.0"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef packageamodule = {
    PyModuleDef_HEAD_INIT,
    "package_a",
    NULL,
    -1,
    PackageAMethods
};

PyMODINIT_FUNC PyInit_package_a(void) {
    return PyModule_Create(&packageamodule);
}
