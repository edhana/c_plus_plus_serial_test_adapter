#include <iostream>
#include "tests.h"
#include "serial.h"

using namespace std;

void Tests::setup(){
	// serial = new Serial("/dev/ttyUSB0", 115200); // Linux	
	serial = new Serial("/dev/tty.PL2303-00001004", 115200); //OSX
}

void Tests::should_connect_with_serial(){
	bool connect_result = serial->connect();
	ASSERT_ISTRUE(connect_result);
}

void Tests::should_send_two_bytes_array(){
	char byte_array[2] = {'a','a'};
	ASSERT_ISTRUE(serial->send(byte_array, 2));
}

void Tests::should_read_two_b_letters(){
	char byte_array_write[2] = {'a','a'};
	char byte_array_read[2];
	char expected[2] = {'b', 'b'};

	ASSERT_ISTRUE(serial->send(byte_array_write, 2));	
	serial->receive(byte_array_read);
	ASSERT_EQUALS_STRING(byte_array_read, expected);
}



