#include "tests.h"

int main(int argc, char **argv){
    Tests tests;
    tests.setup();
    tests.run_tests();
    end_tests();
}
