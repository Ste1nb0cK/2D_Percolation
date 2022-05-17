SHELL = /bin/sh
#specify .o names
OBJ_DIR = ./build_tests
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


test_size.x: build_tests/test_size.o
	${CXX} ${CXXFLAGS} ${PROFILEFLAG} ${SANITIZERS} ${INCLUDES} -o $@ \
	$(shell find ${OBJ_DIR} -name '*.o')

test_percolation.x: build_tests/test_percolation.o
	${CXX} ${CXXFLAGS} ${PROFILEFLAG} ${SANITIZERS} ${INCLUDES} -o $@ \
	$(shell find ${OBJ_DIR} -name '*.o')


test_percolation.cpp: build_tests/test_percolation.o


build_tests/test_size.o: test_size.cpp
	@echo "#Building test_percolation.o"
	${CXX} ${CXXFLAGS} ${PROFILEFLAG} ${SANITIZERS} ${INCLUDES} ${TESTFLAG} \
	-c test_percolation.cpp -o $@


build_tests/test_size.o: test_size.cpp
	@echo "#Building test_size.o"
	${CXX} ${CXXFLAGS} ${PROFILEFLAG} ${SANITIZERS} ${INCLUDES} ${TESTFLAG} \
	-c test_size.cpp -o $@

clean:
	-rm -f ${OBJ_DIR}/*.o foo* *.out *.x
