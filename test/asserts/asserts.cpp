#include <asserts.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

typedef struct test_struct{
    const char *name;
    int passed;
    int number_of_asserts;
    int assertions_failed;
    char failures[50][100];
} TEST;

int number_of_asserts = 0;
int current_test_number = 0;

int pass = 0;
int fail = 0;
const char *test_names[100];
char failures[50][100];

TEST tests[50];

int test_exists(const char* test_name){

	if(current_test_number==0){
		test_names[current_test_number] = test_name;
		
		tests[current_test_number].name = test_name;
		tests[current_test_number].passed = 1;
		tests[current_test_number].number_of_asserts = 0;
		tests[current_test_number].assertions_failed = 0;
		
		return 0;
	}
	else{
		if(!strcmp(test_names[current_test_number-1], test_name)){
			return 1;
		}
		else{
			test_names[current_test_number] = test_name;
			
			tests[current_test_number].name = test_name;
			tests[current_test_number].passed = 1;
		    tests[current_test_number].number_of_asserts = 0;
		    tests[current_test_number].assertions_failed = 0;
			return 0;
		}
	}
		
	return 0;
}

int append_failure(const char* file, const char *test_name, int line, const char* error){
	sprintf(failures[fail-1], "%s: %s\n", test_name, error);
	
	tests[current_test_number-1].passed = 0;
	sprintf(tests[current_test_number-1].failures[tests[current_test_number-1].assertions_failed++], "line %d: %s\n", line, error);
	return 0;
}

int assert_equals_string(const char* file, const char *test_name, int line, char *actual, char *expected){
	if(!test_exists(test_name)){
		current_test_number++;
	}

 	if(strcmp(actual,expected)){
		char failure_content[100];
		sprintf(failure_content, "expected [%s] but was [%s]", expected, actual);
		append_failure(file, test_name, line, failure_content);
 	}
}

int assert_equals_string(const char* file, const char *test_name, int line, char *actual, const char *expected){
	if(!test_exists(test_name)){
		current_test_number++;
	}

 	if(strcmp(actual,expected)){
		char failure_content[100];
		sprintf(failure_content, "expected [%s] but was [%s]", expected, actual);
		append_failure(file, test_name, line, failure_content);
 	}
}

int assert_equals_string(const char* file, const char *test_name, int line, const char *actual, char *expected){
	if(!test_exists(test_name)){
		current_test_number++;
	}

 	if(strcmp(actual,expected)){
		char failure_content[100];
		sprintf(failure_content, "expected [%s] but was [%s]", expected, actual);
		append_failure(file, test_name, line, failure_content);
 	}
}

int assert_equals_string(const char* file, const char *test_name, int line, const char *actual, const char *expected){
	if(!test_exists(test_name)){
		current_test_number++;
	}

 	if(strcmp(actual,expected)){
		char failure_content[100];
		sprintf(failure_content, "expected [%s] but was [%s]", expected, actual);
		append_failure(file, test_name, line, failure_content);
 	}
}

int assert_equals_int(const char* file, const char *test_name, int line, int actual, int expected){

	if(!test_exists(test_name)){
		current_test_number++;
	}

 	if(actual!=expected){
		char failure_content[100];
		sprintf(failure_content, "expected [%d] but was [%d]", expected, actual);
		append_failure(file, test_name, line, failure_content);
 	}
}
 
int assert_equals_float(const char* file, const char *test_name, int line, float actual, float expected, float delta){
	if(!test_exists(test_name)){
		current_test_number++;
	}

 	if(!((actual >= expected - delta) && (actual <= expected + delta))){
		char failure_content[100];
 		sprintf(failure_content, "expected [%f] but was [%f]", expected, actual);
		append_failure(file, test_name, line, failure_content);
 	}
}

int assert_true(const char* file, const char *test_name, int line, bool actual){
	if(!test_exists(test_name)){
		current_test_number++;
	}

 	if(!actual){
		char failure_content[100];
 		sprintf(failure_content, "expected [true] but was [false]");
		append_failure(file, test_name, line, failure_content);
 	}
 	return 0;
}

int assert_not_timeout(const char* file, const char *test_name, int line, bool actual){
	if(!test_exists(test_name)){
		current_test_number++;
	}

 	if(!actual){
		char failure_content[100];
 		sprintf(failure_content, "you've got a timeout");
		append_failure(file, test_name, line, failure_content);
 	}
 	return 0;
}


int end_tests(){
	
    int i,j;

    printf("\n\t");

	//result only with points and f's
	for(i=0; i<current_test_number; i++){
		if(tests[i].passed){
		    printf(".");
		}
		else{
		    printf("F");
		}
	}
	
	printf("\n\n");
	
	//it specifies the failure or error place
	int number_of_failed_tests = 0;
	for(i=0; i<current_test_number; i++){
	    if(!tests[i].passed){
		    printf("\t\t%d) %s\n", ++number_of_failed_tests, tests[i].name);
		    for(j=0; j<tests[i].assertions_failed; j++){
		        printf("\t\t\t%s", tests[i].failures[j]);
		    }
		    printf("\n");
		}
	}
	
	//show overview result
	printf("\n\t%d %s\n", current_test_number, (current_test_number<=1)?"test was executed":"tests were executed");
	printf("\t\tpassed: %d\n", current_test_number-number_of_failed_tests);
	printf("\t\tfailed: %d\n\n", number_of_failed_tests);
	return 0;
}
