#ifndef TESTS_H
#define TESTS_H

#include "asserts.h"
#include "serial.h"

class Tests{
public:
	
	void setup();
	
	// ---> add tests prototypes here
	void should_connect_with_serial();
	void should_send_two_bytes_array();
	void should_read_two_b_letters();
	// void should_send_byte_to_serial();
	// void should_send_byte_array();

	void run_tests(){
		// ---> register tests to be executed here
		ADD_TEST(should_connect_with_serial);
		ADD_TEST(should_send_two_bytes_array);
		ADD_TEST(should_read_two_b_letters);
      	// ADD_TEST(should_send_byte_to_serial);
      	// ADD_TEST(should_send_byte_array);
	}

	//constructor
	Tests(){
	}

	//destructor
	~Tests(){
	}
private:
	Serial *serial;
};
#endif
