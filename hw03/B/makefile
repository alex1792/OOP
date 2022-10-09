CC = g++
CFLAGS = -g 
SRC = main
EXE = $(patsubst %.cpp, %, $(SRC))

all: ${EXE}
	
%:	%.cpp
	${CC} ${CFLAGS} $@.cpp -o $@

clean:
	rm ${EXE}