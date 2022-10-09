#include "Circle.h"
#define pi 3.1415926

Circle::Circle(const string &s, const int r) : Shape(s)
{
    this->radius = r;
    std::cout << "Circle object created..." << endl
              << endl;
}

void Circle::print()
{
    Shape::print();
    std::cout << "circle, radious " << this->radius;

    if (this->radius > 0)
    {
        std::cout << ", area " << this->get_area() << endl;
    }
    else
    {
        std::cout << "(radius must greater than 0)" << endl;
    }
}

double Circle::get_area()
{
    if (this->radius > 0)
    {
        double tmp = radius * radius * pi;
        return tmp;
    }
    else
    {
        std::cout << "radius must greater than 0" << endl;
        return 0.0;
    }
}