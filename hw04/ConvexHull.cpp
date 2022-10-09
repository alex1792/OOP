#include <iostream>
#include <vector>
#include <math.h>
#include <sys/time.h>
#include "Line.cpp"
#define infinite 9999999
#define PI 3.1415926535897931
using namespace std;

class ConvexHull
{ // a class for finding convex hull of a set of points. Input is a const pass by reference vector<Point>, output is a pass by reference vector<Point>
public:
    void FindConvexHull(const std::vector<Point> &input, std::vector<Point> &output); // find the convex hull of input points
private:
    Line FindLine(const Point &p, const Point &q);                       // return a directed line pq from point p to q
    bool isOnRight(const Point &p, const Point &q, const Point &r);      // return true if r is on the right side of the line from p to q. If pq is horizontal, return true only if r is above it.
    Point FindLowestPoint(std::vector<Point> &input);                    // find the lowest point(the point with the smallest y-coordinate)
    double ComputeAngle(const Point &p, const Point &q, const Point &r); // find the angle pqr of three points
};

void ConvexHull::FindConvexHull(const std::vector<Point> &input, std::vector<Point> &Output)
{
    // time
    float time_use = 0;
    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);

    // find lowest y coordinate and left most point
    double lowest_y_coor = input[0].y_pos();
    int lowest_idx = 0;
    // int left_most_idx = 0;
    for (int i = 0; i < input.size(); i++)
    {
        // find lowest y coordinate
        if (lowest_y_coor > input[i].y_pos())
        {
            lowest_y_coor = input[i].y_pos();
            lowest_idx = i;
        }
        // idx of left-most point
        // if (input[i].x_pos() < input[left_most_idx].x_pos())
        // {
        //     left_most_idx = i;
        // }
    }

    // initialize point p, q, r
    Point p = Point(-infinite, lowest_y_coor);
    Point q = input[lowest_idx];
    Point r = input[(lowest_idx + 1) % input.size()];

    // find all edge points
    while (!(r == input[lowest_idx]))
    {
        double maxAngle = 181.0;
        int max_angle_idx = 0;
        for (int i = 0; i < input.size(); i++)
        {
            r = input[i];

            // check point r is already in Output or not
            bool is_in_Output = false;
            for (int j = 0; j < Output.size(); j++)
            {
                if (Output[j] == r)
                {
                    is_in_Output = true;
                    break;
                }
            }

            // if r is p, q or already in Output vector
            // skip this point
            if (r == p || r == q || is_in_Output)
            {
                continue;
            }

            double tmpAngle = ComputeAngle(p, q, r);
            if (tmpAngle < maxAngle)
            {
                maxAngle = tmpAngle;
                max_angle_idx = i;
            }
        }
        r = input[max_angle_idx];
        Output.push_back(r);
        p = q;
        q = r;
    }

    gettimeofday(&end, NULL);
    time_use = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) * 0.001; // msec
    std::cout << "Time of Jarvis March: " << time_use << " msec" << endl;
}

Line ConvexHull::FindLine(const Point &p, const Point &q)
{
    double a = p.y_pos() - q.y_pos();
    double b = q.x_pos() - p.x_pos();
    double c = (-a) * p.x_pos() - b * p.y_pos();
    Line line = Line(a, b, c);
    return line;
}

bool ConvexHull::isOnRight(const Point &p, const Point &q, const Point &r)
{
    Line line = FindLine(p, q);
    double tmp = line.computeValue(r);
    double lineSlope = line.slope();
    if (tmp > 0)
    {
        if (lineSlope > 0)
        {
            return false;
        }
        else if (lineSlope < 0)
        {
            return true;
        }
    }
    else if (tmp < 0)
    {
        if (lineSlope > 0)
        {
            return true;
        }
        else if (lineSlope < 0)
        {
            return false;
        }
    }
    return false;
}

// find the lowest point(the point with the smallest y-coordinate)
Point ConvexHull::FindLowestPoint(std::vector<Point> &input)
{
    Point lowest = input[0];
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i].y_pos() < lowest.y_pos())
        {
            lowest = input[i];
        }
    }
    return lowest;
}

// find the angle pqr of three points
double ConvexHull::ComputeAngle(const Point &p, const Point &q, const Point &r)
{
    double x1 = q.x_pos() - p.x_pos();
    double y1 = q.y_pos() - p.y_pos();
    double x2 = r.x_pos() - q.x_pos();
    double y2 = r.y_pos() - q.y_pos();

    double angle = (x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2));
    angle = acos(angle) * 180 / PI;

    return angle;
}