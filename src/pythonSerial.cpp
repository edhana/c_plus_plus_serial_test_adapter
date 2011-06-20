#include "pythonSerial.h"
#include "Python.h" 

PythonSerial::PythonSerial(const char *serialPort, int speed){
	Py_Initialize();
}

PythonSerial::~PythonSerial(){
	Py_Finalize();
}


