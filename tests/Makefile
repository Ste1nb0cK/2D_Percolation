SHELL = /bin/sh
#specify .o names
SRC_DIR = ./src
OBJ_DIR = ./build_tests
SRCS = $(shell find ${SRC_DIR} -name '*.cpp')
#ma1n_code.o is not included here to make compiling the tests easier
OBJS =  hood.o clouster_matrix.o fill.o index_matrix.o path.o \
percolation.o sep.o size_clouster.o
TESTSDIR = ./tests
#specify to the compiler where to find the headers
INCLUDES = -I "../include"
#compiler specifications
CXX = g++
CXXFLAGS = -Wall -O3
SANITIZERS = -fsanitize=leak -fsanitize=address -fsanitize=leak
DEBUGFLAG = -g
PROFILEFLAG= -pg
#File list used for each test
FILESTESTSIZE = clouster_matrix.cpp percolation.cpp index_matrix.cpp
TESTFLAG = $(shell pkg-config --cflags catch2)
#specify profile report name



test_size.x:
#copy the .o already builded and delete the one with the main function
	cp ../build/* build_tests/
	@-rm tests/build_tests/main1_code.o
	${CXX} ${CXXFLAGS} ${PROFILEFLAG} ${SANITIZERS} ${INCLUDES} ${TESTFLAG} \
	-c test_size.cpp -o build_tests/test_size.o
	${CXX} ${CXXFLAGS} ${PROFILEFLAG} ${SANITIZERS} ${INCLUDES} -o $@ $(shell find ${OBJ_DIR} -name '*.o')
