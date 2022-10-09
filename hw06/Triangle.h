#ifndef Triangle_Header
#define Triangle_Header

#include <iostream>
#include <string>
#include "Shape.h"
using namespace std;

class Triangle : public Shape
{ //derived from Shape using public inheritance
private:
    int height;
    int base;

public:
    Triangle(const string &, const int h, const int b); //takes a string to initialize the triangle's color and two ints to initialize the triangle's height and base. The color string should be passed to the Shape constructor.
    void print() override;                              // takes no argument and return nothing. The method should call the base class print() method to print the color, then print the word "triangle" followed by the triangle's height, base.
    double get_area();                                  // takes no argument and returns the triangle's area (double type) based on its height and base.
};
#endif