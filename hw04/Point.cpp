#include <iostream>
using namespace std;

class Point
{ // representing a point in 2D, (x, y)
public:
    Point() : x(0), y(0){};
    Point(double ix, double iy) : x(ix), y(iy){};
    Point(const Point &p) : x(p.x), y(p.y){};
    bool operator==(const Point &p) { return (x == p.x) && (y == p.y); }
    void print()
    {
        std::cout << x << ", " << y << endl;
    }
    // here, you have to use constant member function
    double x_pos() const
    {
        return x;
    }
    double y_pos() const
    {
        return y;
    }

private:
    double x;
    double y;
};