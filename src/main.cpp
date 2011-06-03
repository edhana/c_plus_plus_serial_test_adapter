#include <Python.h>
#include <iostream>

using namespace std;

int main(){

	// Module configuration
	PyObject *moduleName, *moduleObjetc;

	// Dictionary listing of the module functions
	PyObject *moduleDict;

	// Function
	PyObject *pythonFunction;

  Py_Initialize();
  
  moduleName = PyString_FromString("python_test");

  moduleObjetc = PyImport_Import(moduleName);

  moduleDict = PyModule_GetDict(moduleObjetc);

  pythonFunction = PyDict_GetItemString(moduleDict, "teste");

  // Create the function arguments
  PyObject *arguments;
  arguments = PyTuple_New(2);
  int *a, *b;
  *a=2;
  *b=3;
  PyObject *value1 = Py_BuildValue("I", a);
  PyObject *value2 = Py_BuildValue("I", b);
  
  PyTuple_SetItem(arguments, 0, value1);
  PyTuple_SetItem(arguments, 1, value2);

  // Run the python function
  // PyObject_CallObject(pythonFunction, NULL);
  PyObject *returnValue = PyObject_CallFunction(pythonFunction, "(i,i)", arguments);

  if ( returnValue == NULL ) {
		cout << "The function could not be executed." << endl;
  }

  Py_Finalize();

	return 0;
}