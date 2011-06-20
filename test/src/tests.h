#ifndef TESTS_H
#define TESTS_H

	#include "pythonSerial.h"
	#include "asserts.h"

	class Tests{
		public:
		
			// ---> add tests prototypes here
			void should_connect_serial();
		
			void run_tests(){
				// ---> register tests to be executed here
		      	//ADD_TEST(should_connect_serial);
			}

			//constructor
			Tests(){
			}

			//destructor
			~Tests(){
			}
	};
#endif
