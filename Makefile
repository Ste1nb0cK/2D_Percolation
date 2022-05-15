SHELL = /bin/sh
#specify .o names
SRC_DIR = ./src
OBJ_DIR = ./build
SRCS = $(shell find ${SRC_DIR} -name '*.cpp')
OBJS =  main1_code.o hood.o clouster_matrix.o fill.o index_matrix.o path.o \
percolation.o sep.o size_clouster.o
#specify to the compiler where to find the headers
INCLUDES = -I "./include"
#compiler specifications
CXX = g++
CXXFLAGS = -Wall -O3
SANITIZERS = -fsanitize=leak -fsanitize=address -fsanitize=leak
DEBUGFLAG = -g
PROFILEFLAG= -pg
#specify profile report name
PROF_REPORT = prof_report.txt

#specify where to find the .cpp files
vpath %.cpp ./src
vpath %.o ./build
foo: ${OBJS}
	${CXX} ${CXXFLAGS} ${PROFILEFLAG} ${SANITIZERS} ${INCLUDES} -o $@ $(shell find ${OBJ_DIR} -name '*.o')

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
	
profile:
	./foo 8 0.5 2
	gprof foo gmon.out>${PROF_REPORT} 
	cat ${PROF_REPORT} 
