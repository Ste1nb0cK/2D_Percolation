SHELL = /bin/sh
#specify .o names
SRC_DIR = ./src
OBJ_DIR = ./build
SRCS = $(shell find ${SRC_DIR} -name '*.cpp')
OBJS =  main1_code.o percolation_routines.o fill.o
#specify to the compiler where to find the headers
INCLUDES = -I "./include"
#compiler specifications
CXX = g++
CXXFLAGS = -Wall -fsanitize=address -fsanitize=leak -fsanitize=undefined
DEBUGFLAG = -g

#specify where to find the .cpp files
vpath %.cpp ./src
vpath %.o ./build
foo: ${OBJS}
	${CXX} ${CXXFLAGS} ${INCLUDES} -o $@ $(shell find ${OBJ_DIR} -name '*.o')

clean:
	-rm -f ${OBJ_DIR}/*.o foo*

#implicit rule for making .o from .cpp
.cpp.o:
	@-mkdir build
	${CXX} ${CXXFLAGS} ${INCLUDES} -c $< -o  ${OBJ_DIR}/$@

#format .cpp files using clang format
format:
	clang-format -i --dry-run src/*.cpp
	clang-format -i --dry-run include/*.h
#debug the code
debug:
	${CXX} ${DEBUGFLAG} ${CXXFLAGS} ${INCLUDES} ${SRCS} -o foo_debug
	chmod +x init_debug.sh
	@./init_debug.sh