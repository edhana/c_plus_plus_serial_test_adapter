#include <Python.h> 
#include <string>
#include "pythonSerial.h"

PythonSerial::PythonSerial(const char *serialPort, int speed){
	this->serialPort = new string(serialPort);
	this->speed = speed;

	// Initialize the python interpreter
	Py_Initialize();
}

PythonSerial::~PythonSerial(){
	Py_Finalize();
}

bool PythonSerial::connect(){
	return true;
}

int PythonSerial::getSpeed(){
	return speed;
}


