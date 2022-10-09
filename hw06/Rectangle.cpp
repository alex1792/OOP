#include "Rectangle.h"

Rectangle::Rectangle(const string &s, const int h, const int w) : Shape(s)
{
    this->height = h;
    this->width = w;
    std::cout << "Rectangle object created..." << endl
              << endl;
}

void Rectangle::print()
{
    Shape::print();
    std::cout << "rectangle, height " << this->height << ", width " << this->width;

    if (this->height > 0 && this->width > 0)
    {
        std::cout << ", area " << this->get_area() << endl;
    }
    else
    {
        if (this->height <= 0 && this->width <= 0)
        {
            std::cout << "(both height and width should greater than 0)" << endl;
        }
        else if (this->height <= 0)
        {
            std::cout << "(height should greater than 0)" << endl;
        }
        else if (this->width <= 0)
        {
            std::cout << "(width should greater than 0)" << endl;
        }
    }
}

double Rectangle::get_area()
{
    double tmp = this->height * this->width;
    return tmp;
}
