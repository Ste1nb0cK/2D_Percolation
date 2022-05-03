SHELL = /bin/sh
#specify .o names
OBJS =  main1_code.o percolation_routines.o fill.o
#specify to the compiler where to find the headers
INCLUDES = -I "./include"
#compiler specifications
CXX = g++
CXXFLAGS = -Wall -g

#specify where to find the .cpp files
vpath %.cpp ./src

foo: ${OBJS}
	${CXX} ${CXXFLAGS} ${INCLUDES} -o $@ ${OBJS}

clean:
	-rm -f *.o

#implicit rule for making .o from .cpp
.cpp.o:
	${CXX} ${CXXFLAGS} ${INCLUDES} -c $<

#format .cpp files using clang format
format:
	clang-format -i --dry-run src/*.cpp
	clang-format -i --dry-run include/*.h
