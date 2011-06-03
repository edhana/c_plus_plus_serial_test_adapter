#ifndef ASSERTS_H
#define ASSERTS_H

	#define ASSERT_TRUE(actual) assert_true(__FILE__,__FUNCTION__, __LINE__, actual)
	#define ASSERT_EQUALS_INT(actual, expected) assert_equals_int(__FILE__,__FUNCTION__, __LINE__, actual, expected)
	#define ASSERT_EQUALS_FLOAT(actual, expected, delta) assert_equals_float(__FILE__,__FUNCTION__, __LINE__, actual, expected, delta)
	#define ASSERT_NOT_TIMEOUT(actual) assert_not_timeout(__FILE__,__FUNCTION__, __LINE__, actual)
	#define ASSERT_EQUALS_STRING(actual, expected) assert_equals_string(__FILE__,__FUNCTION__, __LINE__, actual, expected)
	#define ADD_TEST(test) test()

	int assert_equals_int(const char* file, const char *test_name, int line, int actual, int expected);
	int assert_equals_float(const char* file, const char *test_name, int line, float actual, float expected, float delta);
	int assert_true(const char* file, const char *test_name, int line, bool actual);
	int assert_not_timeout(const char* file, const char *test_name, int line, bool actual);
	int assert_equals_string(const char* file, const char *test_name, int line, 	  char *actual,   	  char *expected);
	int assert_equals_string(const char* file, const char *test_name, int line, 	  char *actual, const char *expected);
	int assert_equals_string(const char* file, const char *test_name, int line, const char *actual,   	  char *expected);
	int assert_equals_string(const char* file, const char *test_name, int line, const char *actual, const char *expected);
	int end_tests();
	
#endif
