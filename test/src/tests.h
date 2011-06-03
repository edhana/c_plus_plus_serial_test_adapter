#ifndef TESTS_H
#define TESTS_H

	#include "your_file.h"
	#include "asserts.h"

	class Tests{
		public:
		
			// ---> add tests prototypes here
			void should_do_something();
		
			void run_tests(){
				// ---> register tests to be executed here
		      	ADD_TEST(should_do_something);
			}

			//constructor
			Tests(){
			}

			//destructor
			~Tests(){
			}
	};
#endif
