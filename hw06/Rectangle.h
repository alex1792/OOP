#ifndef Rectangle_Header
#define Rectangle_Header

#include <iostream>
#include <string>
#include "Shape.h"
using namespace std;

class Rectangle : public Shape
{ //derived from Shape using public inheritance
private:
    int height;
    int width;

public:
    Rectangle(const string &s, const int h, const int w); //takes a string to initialize the rectangle's color and two ints to initialize the rectangle's height and width. The color string should be passed to the Shape constructor.
    void print() override;                                // takes no argument and return nothing. The method should call the base class print() method to print the color, then print the word "rectangle" followed by the rectangle's height, width.
    double get_area();                                    // takes no argument and returns the rectangle's area (double type) based on its height and width.
};

#endif