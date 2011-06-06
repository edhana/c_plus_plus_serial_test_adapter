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
  arguments = PyTuple_New(1);
  const char *str1 = "Teste";
  PyObject *stringArgument = PyString_FromFormat("%s", str1);
  
  PyTuple_SetItem(arguments, 0, stringArgument);

  // Run the python function
  PyObject *returnValue;
  returnValue = PyObject_CallObject(pythonFunction, arguments);
  // char * signature = "(arg)";
  // PyObject *returnValue = PyObject_CallFunction(pythonFunction, signature, arguments);

  if ( returnValue == NULL ) {
		cout << "The function could not be executed." << endl;
  }

  Py_Finalize();

	return 0;
}