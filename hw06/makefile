main:main.o Shape.o Circle.o Rectangle.o Triangle.o
	g++ -o main main.o Shape.o Circle.o Rectangle.o Triangle.o
Shape.o:Shape.h Shape.cpp
	g++ -c Shape.cpp
Circle.o:Circle.h Circle.cpp
	g++ -c Circle.cpp
Rectangle.o:Rectangle.h Rectangle.cpp
	g++ -c Rectangle.cpp
Triangle.o:Triangle.h Triangle.cpp
	g++ -c Triangle.cpp
main.o:main.cpp
	g++ -c main.cpp
clean:
	rm *.o
	rm main
