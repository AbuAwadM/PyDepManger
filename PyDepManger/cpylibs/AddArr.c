/**
* 9-3-2025 updated, py 3.13.2 , clang c17
**/
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <numpy/arrayobject.h>

// Org C Code 
void addARR(int * arr1, int * arr2, int narrs, int * result){    
    int i = 0;
    for(i = 0; i < narrs; i++){
        result[i] = arr1[i] + arr2[i];
    }
}

// Wrapper for it to work cross-platform and for packaging

// 1 Input Declaration, verification, then conversion
// Boilerplates //
// 2 Declare method
// 3 Declare module as in file
// 4 Create module to be recognized

static PyObject* py_addARR(PyObject* self, PyObject* args) {
    PyObject *arr1_obj;
    PyObject *arr2_obj;
    int narrs;
    PyObject *result_obj;

    // O = Object , i = integer // see https://docs.python.org/3/c-api/arg.html#other-objects
    if (!PyArg_ParseTuple(args, "OOiO", &arr1_obj, &arr2_obj, &narrs, &result_obj)) {
        return NULL;
    }

    // Casting
    int *arr1 = (int*) PyArray_DATA((PyArrayObject*) arr1_obj);
    int *arr2 = (int*) PyArray_DATA((PyArrayObject*) arr2_obj);
    int *result = (int*) PyArray_DATA((PyArrayObject*) result_obj);

    addARR(arr1, arr2, narrs, result);

    Py_INCREF(result_obj);
    return Py_BuildValue("O", result_obj);
}

static PyMethodDef AddMethods[] = {
    {"addARR", py_addARR, METH_VARARGS, "Add two arrays element-wise"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef AddModules = {
    PyModuleDef_HEAD_INIT,
    "addARR",
    NULL,
    -1,
    AddMethods
};

PyMODINIT_FUNC PyInit_AddArr(void) {
    import_array();
    return PyModule_Create(&AddModules);
}





