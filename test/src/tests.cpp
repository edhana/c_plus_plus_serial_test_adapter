#include "tests.h"

void Tests::should_do_something() {

	// ---> write your test here
	int response = your_function();
	ASSERT_EQUALS_INT(response,0);

	//asserts examples 
	/*
    ASSERT_TRUE(false);
    ASSERT_EQUALS_INT(1,2);
    ASSERT_EQUALS_FLOAT(3.2,3.22,0.01);
    ASSERT_EQUALS_STRING("oi", "oi1");
	*/
}
