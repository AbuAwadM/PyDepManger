#include <Python.h>

static PyObject* helloworld(PyObject* self, PyObject* args) {
    printf("Hello, World!\n");
    Py_RETURN_NONE;
}

static PyMethodDef HelloWorldMethods[] = {
    {"helloworld", helloworld, METH_VARARGS, "Print 'Hello, World!'"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef helloworldmodule = {
    PyModuleDef_HEAD_INIT,
    "helloworld",
    NULL,
    -1,
    HelloWorldMethods
};

PyMODINIT_FUNC PyInit_helloworld(void) {
    return PyModule_Create(&helloworldmodule);
}