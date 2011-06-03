#paths to compile files
vpath %.cpp ../src
vpath %.cpp ../test/asserts
vpath %.cpp ../test/src
vpath %.h ../src
vpath %.h ../include
vpath %.h ../test/asserts
vpath %.h ../test/src

#include header files
CXXFLAGS = -I ../src -I ../test/src -I ../test/asserts -I ../include
CFLAGS = $(CXXFLAGS) 

#external libraries
LXXFLAGS = 
LDFLAGS = $(LXXFLAGS)

#force to use g++
CC = g++
CXX = g++

#executable to be generated
MAIN_NAME = all_tests

#your code objects
OBJ = your_file.o

#test objects
TEST_OBJ = asserts.o tests.o $(MAIN_NAME).o

#'make' command will run tests
all:
	make test
	
$(MAIN_NAME): $(TEST_OBJ) $(OBJ)

test:
	make $(MAIN_NAME)
	./$(MAIN_NAME)

#objects removing
.PHONY: clean
clean:
	rm -fv *.o $(MAIN_NAME)
