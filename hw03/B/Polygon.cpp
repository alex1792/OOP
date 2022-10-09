#include <iostream>
#include "LinkedList.cpp"
using namespace std;

class Polygon
{
public:
    Polygon();  // constructor
    ~Polygon(); // destructor
                // While coding, please insert a line
                // cout << “Constructing Polygon…” << endl;
                // and
                // cout << “Deleting Polygon…” << endl;
                // in the body of constructor and destructor, respectively.

    // It takes an array of points and forms a polygon
    void setPolygon(Point pts[], int size)
    {
        vertexList.clear();
        for (int i = 0; i < size; i++)
        {
            vertexList.insertToNext(pts[i]);
            vertexList.pointToNext();
        }
    }
    Polygon *splitPolygon();            // To be implemented
    bool isCollide(Polygon &inPolygon); // To be implemented
    // The input edge is defined by 2 end points − ptA and ptB
    // This function returns true if the input edge intersects
    // or touches this polygon. Otherwise, it returns false.
    // Implemented for you
    bool isEdgeIntersect(const Point &ptA, const Point &ptB);

private:
    LinkedList vertexList; // The circular doubly linked list
};

Polygon::Polygon()
{
    std::cout << "Constructing polygon..." << endl;
}

Polygon::~Polygon()
{
    std::cout << "Destructing polygon..." << endl;
}

Polygon *Polygon::splitPolygon()
{
    Polygon *polyCopy = new Polygon;
    // Point tmp = vertexList.getCurrentPoint();
    // std::cout << "in splitPolygon(), current_pointer of a: " << tmp.x << "," << tmp.y << endl;

    int n = vertexList.getSize();
    if (n <= 3)
    {
        return NULL;
    }
    // Point tmp = vertexList.getCurrentPoint();
    // std::cout << "current point before copy: " << tmp.x << "," << tmp.y << endl;
    int m = (n / 2) + 1;
    std::cout << "copy_a:" << endl;
    for (int i = 0; i < m; i++)
    {
        Point tmp = vertexList.getCurrentPoint();
        std::cout << tmp.x << "," << tmp.y << endl;
        polyCopy->vertexList.insertToNext(tmp);
        vertexList.pointToNext();
    }

    for (int i = 0; i < n - m; i++)
    {
        vertexList.deleteCurrentNode();
    }

    return polyCopy;
}

bool Polygon::isCollide(Polygon &inPolygon)
{
    int edgeSize = inPolygon.vertexList.getSize();
    int falseCnt = 0;
    for (int i = 0; i < edgeSize; i++)
    {
        Point a = inPolygon.vertexList.getCurrentPoint();
        inPolygon.vertexList.pointToNext();
        Point b = inPolygon.vertexList.getCurrentPoint();

        bool flag = isEdgeIntersect(a, b);
        // there exist cross of edges
        if (flag == true)
        {
            falseCnt++;
        }
    }
    // no cross, so no collision
    if (falseCnt == 0)
    {
        return true;
    }

    return false;
}