CC = g++
CFLAGS = -g 
SRC = main_stack main_tree
EXE = $(patsubst %.cpp, %, $(SRC))

all: ${EXE}
	
%:	%.cpp
	${CC} ${CFLAGS} $@.cpp -o $@

clean:
	rm ${EXE}