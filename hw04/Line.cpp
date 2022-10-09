#include <iostream>
#include "Point.cpp"
using namespace std;

class Line
{ // representing a line in 2D, a*x + b*y + c = 0
public:
    // a(0) represents the initialization of variable a
    Line() : a(0), b(0), c(0){};
    Line(double ia, double ib, double ic) : a(ia), b(ib), c(ic){};
    Line(const Line &p) : a(p.a), b(p.b), c(p.c){};
    bool operator==(const Line &p) { return (a == p.a) && (b == p.b) && (c == p.c); }
    double computeValue(const Point &pt);
    double slope();

private:
    double a;
    double b;
    double c;
};

double Line::computeValue(const Point &pt)
{
    double ret = a * pt.x_pos() + b * pt.y_pos() + c;
    return ret;
}

double Line::slope()
{
    return -a / b;
}