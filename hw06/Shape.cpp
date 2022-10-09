#include "Shape.h"

Shape::Shape(const string &s)
{
    color = s;
    std::cout << "Shape object created..." << endl;
}

void Shape::print()
{
    std::cout << color << " ";
}
