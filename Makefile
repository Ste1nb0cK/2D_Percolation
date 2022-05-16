SHELL = /bin/sh
#specify .o names
SRC_DIR = ./src
OBJ_DIR = ./build
TEST_OBJ_DIR = ./tests/build_tests
SRCS = $(shell find ${SRC_DIR} -name '*.cpp')
#ma1n_code.o is not included here to make compiling the tests easier
OBJS =  hood.o clouster_matrix.o fill.o index_matrix.o path.o \
percolation.o sep.o size_clouster.o
TESTSDIR = ./tests
#specify to the compiler where to find the headers
INCLUDES = -I "./include"
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
PROF_REPORT = prof_report.txt

#specify where to find the .cpp files
vpath %.cpp ./src
vpath %.o ./build
foo: ${OBJS}
	${CXX} ${CXXFLAGS} ${PROFILEFLAG} ${SANITIZERS} ${INCLUDES} -o $@\
	$(shell find ${OBJ_DIR} -name '*.o')

clean:
	-rm -f ${OBJ_DIR}/*.o foo* *.out ${PROF_REPORT}

#implicit rule for making .o from .cpp
.cpp.o:
	@-mkdir build
	${CXX} ${CXXFLAGS} ${PROFILEFLAG} ${SANITIZERS} ${INCLUDES} -c $< -o  ${OBJ_DIR}/$@

#format .cpp files using clang format
format:
	clang-format -i --dry-run src/*.cpp
	clang-format -i --dry-run include/*.hpp
#debug the code
debug:
	${CXX} ${DEBUGFLAG}  ${INCLUDES} ${SRCS} -o foo_debug
	chmod +x init_debug.sh
	./init_debug.sh
report:

simu1:
	./foo 4 0.6 1

profile:
	./foo 8 0.5 2
	gprof foo gmon.out>${PROF_REPORT} 
	cat ${PROF_REPORT} 

test_size.x: ${FILESTESTSIZE} tests/test_size.cpp
#copy the .o already builded and delete the one with the main function
	cp build/* tests/build_tests/
	@-rm tests/build_tests/main1_code.o
	${CXX} ${CXXFLAGS} ${PROFILEFLAG} ${SANITIZERS} ${INCLUDES} ${TESTFLAG} \
	-c tests/test_size.cpp -o ./tests/build_tests/test_size.o
	${CXX} ${CXXFLAGS} ${PROFILEFLAG} ${SANITIZERS} ${INCLUDES} -o $@ $(shell find ${TESTS_OBJ_DIR} -name '*.o')
