#ifndef Circle_Header
#define Circle_Header

#include <iostream>
#include <string>
#include "Shape.h"
using namespace std;

class Circle : public Shape
{ //derived from Shape using public inheritance
private:
    int radius;

public:
    Circle(const string &s, const int r); // takes a string to initialize the circle's color and an int to initialize the circle's radius. The color string should be passed to the Shape constructor.
    void print() override;                // takes no argument and return nothing. This method should call the base print() method to print the color, then print the word "circle" followed by the circle's radius and area.
    double get_area();                    // takes no arguments and return the circle's area (double type) based on its radius.
};

#endif