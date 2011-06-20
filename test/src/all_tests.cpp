#include "tests.h"
#include "gmock/gmock.h"

int main(int argc, char **argv){
	// Google mock thing
	::testing::InitGoogleMock(&argc, argv);

    Tests tests;
    tests.run_tests();
    end_tests();
}
