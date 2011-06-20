#ifndef PYTHON_SERIAL_H
#define PYTHON_SERIAL_H

#include <Python.h>
#include <string>

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
	PyObject *serialModule;
	PyObject *connectFunction;
	PyObject *sendFunction;

	// Attributes
	string *serialPort;
	int speed;
};

#endif
