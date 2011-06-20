#include <Python.h>
#include <iostream>

using namespace std;

int main(){

  Py_Initialize();
  
  // Module configuration
  PyObject *moduleName;
  moduleName = PyString_FromString("python_test");

  // Import the python module
  PyObject *moduleObject;
  moduleObject = PyImport_Import(moduleName);

	// Dictionary listing of the module functions
	PyObject *moduleDict;
  moduleDict = PyModule_GetDict(moduleObject);

  // Open Serial Connection
  PyObject *pySerialConnFunction;
  pySerialConnFunction =  PyDict_GetItemString(moduleDict, "open_serial_comm");

  // Send bytes function
  PyObject *pythonFunction;
  pythonFunction = PyDict_GetItemString(moduleDict, "send_bytes");

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