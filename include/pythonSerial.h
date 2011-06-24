#ifndef PYTHON_SERIAL_H
#define PYTHON_SERIAL_H

#include <Python.h>
#include <string>
#include "serial.h"

#define PYTHON_MODULE_NAME "python_test"
#define PYTHON_CONNECTION_FUNCTION "open_serial_conection"

using namespace std;

class PythonSerial: public Serial{
public:
	PythonSerial(const char * serialPort, int speed);
	bool connect();
	~PythonSerial();
private:
	// Python Module Definition
	PyObject *moduleName;
	PyObject *moduleObject;
	PyObject *moduleFunctions; //Dictionary of module functions
	PyObject *connectionFunction;
	PyObject *connectionFunctionArguments;
};

class PythonSerialMock: public Serial{
public:
	
};

#endif
