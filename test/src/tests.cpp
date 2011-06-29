#include <iostream>
#include "tests.h"
#include "serial.h"

using namespace std;

void Tests::setup(){
	// serial = new Serial("/dev/ttyUSB0", 115200); // Linux	
	serial = new Serial("/dev/tty.PL2303-00004226", 115200); //OSX
}

void Tests::should_connect_with_serial(){
	ASSERT_ISTRUE(serial->connect());	
}

// void Tests::should_send_byte_to_serial(){
// 	ASSERT_ISTRUE(serial->send('a'));
// }

void Tests::should_send_byte_array(){
	char byteArray[2] = {'a','a'};

	ASSERT_ISTRUE(serial->send(byteArray, 2));
}



