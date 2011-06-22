#ifndef PYTHON_SERIAL_H
#define PYTHON_SERIAL_H

#include <Python.h>
#include <string>

#define PYTHON_MODULE_NAME "python_test"
#define PYTHON_CONNECTION_FUNCTION "open_serial_conection"

using namespace std;

class PythonSerial{
public:
	PythonSerial(const char * serialPort, int speed);
	bool connect();
	int getSpeed();
	~PythonSerial();
private:
	// Python Module Definition
	PyObject *moduleName;
	PyObject *moduleObject;
	PyObject *moduleFunctions; //Dictionary of module functions
	PyObject *connectionFunction;
	PyObject *connectionFunctionArguments;

	// Attributes
	string *serialPort;
	int speed;
};

#endif
