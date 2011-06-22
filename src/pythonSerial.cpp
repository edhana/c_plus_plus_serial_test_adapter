#include <Python.h> 
#include <string>
#include "pythonSerial.h"

PythonSerial::PythonSerial(const char *serialPort, int speed){
    this->serialPort = new string(serialPort);
    this->speed = speed;

    // Initialize the python interpreter
    Py_Initialize();

    // Module name configuration
    moduleName = PyString_FromString(PYTHON_MODULE_NAME);

    // Import the python serial module
    moduleObject = PyImport_Import(moduleName);

    // Dictionary listing of the module functions
    moduleFunctions = PyModule_GetDict(moduleObject);

    // Retrieve the Function which connects with the serial
    connectionFunction =  PyDict_GetItemString(moduleFunctions, PYTHON_CONNECTION_FUNCTION);

}

PythonSerial::~PythonSerial(){
    Py_Finalize();
}

bool PythonSerial::connect(){
    // Create the default arguments to fill the connect function identifier
    connectionFunctionArguments = PyTuple_New(2);
    PyObject *serialPortArgument = PyString_FromFormat("%s", "/dev/ttyUSB0");
    PyObject *speedArgument = PyInt_FromLong(speed);
    PyTuple_SetItem(connectionFunctionArguments, 0, serialPortArgument);
    PyTuple_SetItem(connectionFunctionArguments, 1, speedArgument);

    // Run the connection function
    PyObject *returnValue;
    // returnValue = PyObject_CallObject(connectionFunction, NULL);
    returnValue = PyObject_CallObject(connectionFunction, connectionFunctionArguments);
    return true;
}

int PythonSerial::getSpeed(){
    return speed;
}


