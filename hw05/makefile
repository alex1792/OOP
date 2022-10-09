main:Mixed.o main.o
	g++ -o main Mixed.o main.o
Mixed.o:Mixed.h Mixed.cpp
	g++ -c Mixed.cpp
main.o:main.cpp
	g++ -c main.cpp
clean:
	rm *.o
	rm main
