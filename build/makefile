#paths to compile files
vpath %.cpp ../src
vpath %.cpp ../test/asserts
vpath %.cpp ../test/src
vpath %.h ../src
vpath %.h ../include
vpath %.h ../test/asserts
vpath %.h ../test/src

# Google Mock configuration - It's necessary to configure if the library is not installed on your system.
# GMOCK_DIR = ~/home_libs/gmock-1.6.0
# GTEST_DIR = $(GMOCK_DIR)/gtest

#include header files
CXXFLAGS = -I ../src -I ../test/src -I ../test/asserts -I ../include -I/usr/include/python2.6 -fno-strict-aliasing -g -O2 -DNDEBUG -g -fwrapv -O2 -Wall -Wno-write-strings
CFLAGS = $(CXXFLAGS) 

#external libraries
LXXFLAGS = -lpython2.6 -lm -lgtest -lgmock
LDFLAGS = $(LXXFLAGS)

#force to use g++
CC = g++
CXX = g++

#executable to be generated
MAIN_NAME = hadapter
MAIN_NAME_TEST = all_tests

#your code objects
OBJ = pythonSerial.o

#test objects
TEST_OBJ = asserts.o tests.o $(MAIN_NAME_TEST).o

#'make' command will run tests
all: $(OBJ)
	$(CXX) $(LDFLAGS) $(OBJ) -o $(MAIN_NAME)
	mkdir ../bin
	cp $(MAIN_NAME) ../bin
	cp ../src/*.py ../bin
	
	
$(MAIN_NAME): $(TEST_OBJ) $(OBJ)

test_obj: $(TEST_OBJ)

test: $(MAIN_NAME)
	$(CXX) $(OBJ) $(TEST_OBJ) -o all_tests $(LDFLAGS)
	./$(MAIN_NAME_TEST)

#objects removing
.PHONY: clean
clean:
	rm -fv *.o $(MAIN_NAME_TEST) $(MAIN_NAME)
	rm -rf ../bin