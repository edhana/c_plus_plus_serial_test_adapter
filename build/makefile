#paths to compile files
vpath %.cpp ../src
vpath %.cpp ../test/asserts
vpath %.cpp ../test/src
vpath %.h ../src
vpath %.h ../include
vpath %.h ../test/asserts
vpath %.h ../test/src

# Path of the python file
PYTHONPATH = /Users/edhana/workspace/HardwareTestAdapter/src

#include header files
CXXFLAGS = -I ../src -I ../test/src -I ../test/asserts -I ../include -I/usr/include/python2.6 -fno-strict-aliasing -g -O2 -DNDEBUG -g -fwrapv -O2 -Wall -Wno-write-strings
CFLAGS = $(CXXFLAGS) 

#external libraries
LXXFLAGS = -lpython2.6 -lm
LDFLAGS = $(LXXFLAGS)

#force to use g++
CC = g++
CXX = g++

#executable to be generated
MAIN_NAME = hadapter
MAIN_NAME_TEST = all_tests

#your code objects
OBJ = main.o

#test objects
TEST_OBJ = asserts.o tests.o $(MAIN_NAME_TEST).o serial_comm.o serial.o

#'make' command will run tests
all: $(OBJ)
	$(CXX) $(LDFLAGS) $(OBJ) -o $(MAIN_NAME)
	mkdir ../bin
	cp $(MAIN_NAME) ../bin
	cp ../src/*.py ../bin
	
$(MAIN_NAME): $(TEST_OBJ) $(OBJ)

test_obj: $(TEST_OBJ)

test: $(MAIN_NAME)
	$(CXX) $(TEST_OBJ) -o all_tests $(LDFLAGS)
	./$(MAIN_NAME_TEST)
	echo "*** Termino da Execução do Programa ***"

#objects removing
.PHONY: clean
clean:
	rm -fv *.o $(MAIN_NAME_TEST) $(MAIN_NAME) *.py
	rm -rf ../bin