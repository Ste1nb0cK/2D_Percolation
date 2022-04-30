SHELL = /bin/sh
#specify .o names
OBJS = main.o check_count_single.o vertical_routines.o create_filled_grid.o
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
