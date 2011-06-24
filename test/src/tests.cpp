#include "tests.h"
#include "pythonSerial.h"
#include "serial.h"
#include "gmock/gmock.h"

/**
 * This is a silly test to prove that the framework is right
 */
void Tests::should_set_the_right_speed() {
	// Setup
	Serial *serial = new PythonSerial("/dev/ttyUSB0", 115200);

	ASSERT_EQUALS_INT(serial->getSpeed(), 115200);	

	// Tear down
	delete(serial);

}

void Tests::should_connect_serial() {
	Serial *serial = new PythonSerial("/dev/ttyUSB0", 115200);
	bool response = serial->connect();
	ASSERT_ISTRUE(response);
	
	//asserts examples 
	/*
	ASSERT_EQUALS_INT(response,0);
    ASSERT_TRUE(false);
    ASSERT_EQUALS_INT(1,2);
    ASSERT_EQUALS_FLOAT(3.2,3.22,0.01);
    ASSERT_EQUALS_STRING("oi", "oi1");
	*/


	// Tear down
	delete(serial);
}
