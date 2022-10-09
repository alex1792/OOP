#include "Triangle.h"

Triangle::Triangle(const string &s, const int h, const int b) : Shape(s)
{
    this->height = h;
    this->base = b;
    std::cout << "Triangle object created..." << endl
              << endl;
}

void Triangle::print()
{
    Shape::print();
    std::cout << "triangle, height " << this->height << ", width " << this->base;

    if (this->height > 0 && this->base > 0)
    {
        std::cout << ", area " << this->get_area() << endl;
    }
    else
    {
        if (this->height <= 0 && this->base <= 0)
        {
            std::cout << "(both height and width should greater than 0)" << endl;
        }
        else if (this->height <= 0)
        {
            std::cout << "(height should greater than 0)" << endl;
        }
        else if (this->base <= 0)
        {
            std::cout << "(base   should greater than 0)" << endl;
        }
    }
}

double Triangle::get_area()
{
    double tmp = this->height * this->base / 2;
    return tmp;
}