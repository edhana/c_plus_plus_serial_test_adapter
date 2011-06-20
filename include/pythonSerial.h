#ifndef PYTHON_SERIAL_H
#define PYTHON_SERIAL_H

#include <Python.h>

class PythonSerial{
public:
	PythonSerial(const char * serialPort, int speed);
	bool connect();
	~PythonSerial();
private:
	//Describe all the Python objects that will be needed for this class as attributes
	PyObject *moduleName;
	PyObject *serialModule;
	PyObject *connectFunction;
	PyObject *sendFunction;
	//TODO: Read Function
};

#endif
