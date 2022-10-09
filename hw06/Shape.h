#ifndef Shape_Header
#define Shape_Header

#include <iostream>
#include <string>
using namespace std;

class Shape
{
private:
    string color;

public:
    Shape(const string &);         // takes a const string& argument and use it to initialize the Shape's color. Since the Shape class is abstract, this constructor will only be invoked by a derived-class constructor.
    virtual void print();          // virtual method, takes no argument and return nothing. This function should print the color
    virtual double get_area() = 0; //pure virtual method, takes no argument and return the area (double type) of the shape.
};

#endif