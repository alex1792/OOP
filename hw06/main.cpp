#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

int main()
{
    vector<Shape *> shape;
    vector<string> type;
    const int x = 15, y = 30;

    // correct format shapes
    Shape *circle = new Circle("blue", x);
    Shape *a = new Triangle("yellow", x, y);
    Shape *b = new Rectangle("black", x, y);
    Shape *c = new Triangle("red", 3, 5);
    Shape *d = new Circle("green", 7);
    Shape *e = new Rectangle("white", 3, 11);

    // wrong format shape
    Shape *f = new Circle("purple", 0);
    Shape *g = new Rectangle("grey", 0, -1);
    Shape *h = new Triangle("pink", -2, 5);

    shape.push_back(circle);
    type.push_back("circle");
    shape.push_back(a);
    type.push_back("triangle");
    shape.push_back(b);
    type.push_back("rectangle");
    shape.push_back(c);
    type.push_back("triangle");
    shape.push_back(d);
    type.push_back("circle");
    shape.push_back(e);
    type.push_back("rectangle");

    shape.push_back(f);
    type.push_back("circle");
    shape.push_back(g);
    type.push_back("rectangle");
    shape.push_back(h);
    type.push_back("triangle");

    cout << "Printing all shapes:" << endl;
    for (Shape *p : shape)
    {
        p->print();
    }
    std::cout << endl;

    cout << "Print all circle:" << endl;
    for (size_t i = 0; i < shape.size(); i++)
    {
        if (type[i] == "circle")
        {
            shape[i]->print();
        }
    }
    cout << endl;

    cout << "Print all Rectangle:" << endl;
    for (size_t i = 0; i < shape.size(); i++)
    {
        if (type[i] == "rectangle")
        {
            shape[i]->print();
        }
    }
    cout << endl;

    cout << "Print all Triangle:" << endl;
    for (size_t i = 0; i < shape.size(); i++)
    {
        if (type[i] == "triangle")
        {
            shape[i]->print();
        }
    }

    std::cout << endl;
    std::cout << "destruct all shape" << endl;
    for (size_t i = 0; i < shape.size(); i++)
    {
        delete shape[i];
        shape[i] = NULL;
        type[i] = "";
    }
    return 0;
}
