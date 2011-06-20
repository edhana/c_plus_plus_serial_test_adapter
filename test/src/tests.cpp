#include "tests.h"
#include "pythonSerial.h"

void Tests::should_connect_serial() {

	// ---> write your test here
	PythonSerial *serial = new PythonSerial("/dev/ttyUSB0", 115200);
	bool response = serial.connect();
	ASSERT_TRUE(response);
	//asserts examples 
	/*
	ASSERT_EQUALS_INT(response,0);
    ASSERT_TRUE(false);
    ASSERT_EQUALS_INT(1,2);
    ASSERT_EQUALS_FLOAT(3.2,3.22,0.01);
    ASSERT_EQUALS_STRING("oi", "oi1");
	*/
}
