#include <iostream>
#include <fstream>
#include "ConvexHull.cpp"
#include <math.h>
#include <sys/time.h>
using namespace std;

void swap(Point *a, Point *b)
{
    // Point *tmp = new Point(a->x_pos(), a->y_pos());
    // a = new Point(b->x_pos(), b->y_pos());
    // b = tmp;
    Point *tmp = a;
    a = b;
    b = tmp;
}

double angle(const Point &p, const Point &q, const Point &r)
{
    double x1 = q.x_pos() - p.x_pos();
    double y1 = q.y_pos() - p.y_pos();
    double x2 = r.x_pos() - q.x_pos();
    double y2 = r.y_pos() - q.y_pos();

    double angle = (x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2));
    angle = acos(angle) * 180 / PI;

    return angle;
}

void bruteForce(vector<Point> &p, int pointCnt)
{
    // time
    float time_use = 0;
    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);

    // convex hull's edge points
    Point edgePoints[pointCnt];
    int edgeCnt = 0;

    // for all point p in input
    for (int i = 0; i < pointCnt - 1; i++)
    {
        // for all point q in input and point q is not equal to point p
        for (int j = 0; j < pointCnt; j++)
        {
            if (j == i)
            {
                continue;
            }
            // a = Yp - Yq, b = Xq - Xp, c = -ax - by
            double a = p[i].y_pos() - p[j].y_pos();
            double b = p[j].x_pos() - p[i].x_pos();
            double c = (-a) * p[i].x_pos() - b * p[i].y_pos();
            Line *line = new Line(a, b, c);

            // use to count how many points are on the right side of line pq
            int correctCnt = 0;

            // for all the others point in input
            for (int k = 0; k < pointCnt; k++)
            {
                // skip the same point of p or q
                if (k == i || k == j)
                {
                    continue;
                }
                double tmp = a * p[k].x_pos() + b * p[k].y_pos() + c;
                // std::cout << "tmp: " << tmp << endl;

                // on the right
                if (tmp < 0)
                {
                    correctCnt++;
                    continue;
                }
                else if (tmp > 0)
                {
                    break;
                }
            }

            // check if all point r are on the right hand side of line pq
            if (correctCnt == pointCnt - 2)
            {
                // std::cout << "correctCnt: " << correctCnt << endl;
                int pState = 0;
                int qState = 0;
                for (int idx = 0; idx < edgeCnt; idx++)
                {
                    // check point p
                    if (edgePoints[idx].x_pos() == p[i].x_pos() && edgePoints[idx].y_pos() == p[i].y_pos())
                    {
                        pState = 1;
                    }
                    // check point q
                    if (edgePoints[idx].x_pos() == p[j].x_pos() && edgePoints[idx].y_pos() == p[j].y_pos())
                    {
                        qState = 1;
                    }
                    if (pState == 1 && qState == 1)
                    {
                        break;
                    }
                }
                // state == 0, means the point is not in the edgePoints array
                // so push the point into array
                if (pState == 0)
                {
                    edgePoints[edgeCnt++] = p[i];
                }
                if (qState == 0)
                {
                    edgePoints[edgeCnt++] = p[j];
                }
            }
        }
    }

    // copy points in convex hull into inHull array
    Point inHull[pointCnt - edgeCnt];
    int hullCnt = 0;

    for (int i = 0; i < pointCnt; i++)
    {
        int state = 0;
        // check all points in edgePoints array
        for (int j = 0; j < edgeCnt; j++)
        {
            // same, means point p is in edgePoints array
            if (edgePoints[j].x_pos() == p[i].x_pos() && edgePoints[j].y_pos() == p[i].y_pos())
            {
                state = 1;
                break;
            }
        }

        if (state == 0)
        {
            inHull[hullCnt++] = p[i];
        }
    }

    // sort the edge points array
    // find the left most point and swap with
    // edgePoint[0]
    double x_min = edgePoints[0].x_pos();
    int left_most_idx = 0;
    double y_min = edgePoints[0].y_pos();
    int lowest_y_idx = 0;

    // std::cout << "left most point: " << edgePoints[0].x_pos() << ", " << edgePoints[0].y_pos() << endl;
    for (int i = 0; i < edgeCnt; i++)
    {
        if (x_min > edgePoints[i].x_pos())
        {
            x_min = edgePoints[i].x_pos();
            left_most_idx = i;
            // std::cout << "x: " << edgePoints[i].x_pos() << endl;
        }
        if (y_min > edgePoints[i].y_pos())
        {
            y_min = edgePoints[i].y_pos();
            lowest_y_idx = i;
        }
    }

    swap(edgePoints[0], edgePoints[left_most_idx]);

    // // initial point p, q, r
    Point pt = Point(x_min, y_min);
    Point q = edgePoints[0];
    Point r = edgePoints[1];

    for (int i = 1; i < edgeCnt - 1; i++)
    {
        // find max angle
        double minAngle = 180.1;
        int idx = i;
        // in rest of the points
        for (int j = i; j < edgeCnt; j++)
        {
            r = edgePoints[j];
            double tmpAngle = angle(pt, q, r);
            if (tmpAngle < minAngle)
            {
                minAngle = tmpAngle;
                idx = j;
            }
        }

        // swap with ith element
        swap(edgePoints[i], edgePoints[idx]);

        // update point pt and q
        pt = edgePoints[i - 1];
        q = edgePoints[i];
    }

    gettimeofday(&end, NULL);
    time_use = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) * 0.001; // msec
    std::cout << "Time of Brute Force: " << time_use << " msec" << endl;

    // output to file
    fstream Output_brutal;
    Output_brutal.open("Output_brutal.txt", ios::out | ios::trunc);

    // inside convex hull
    Output_brutal << hullCnt << endl;
    for (int i = 0; i < hullCnt; i++)
    {
        Output_brutal << inHull[i].x_pos() << " " << inHull[i].y_pos() << endl;
    }
    Output_brutal << endl;

    // edge points of convex hull
    Output_brutal << edgeCnt << endl;
    for (int i = 0; i < edgeCnt; i++)
    {
        Output_brutal << edgePoints[i].x_pos() << " " << edgePoints[i].y_pos() << endl;
    }
}

void removeEdgePoint(vector<Point> &input, const vector<Point> &output)
{
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < output.size(); j++)
        {
            if (input[i] == output[j])
            {
                input.erase(input.begin() + i);
                i--;
                break;
            }
        }
    }
}

void DrawPoints(const vector<Point> &input)
{
    fstream Output_jarvis;
    Output_jarvis.open("Output_jarvis.txt", ios::out | ios::trunc);

    // inside convex hull
    Output_jarvis << input.size() << endl;
    for (int i = 0; i < input.size(); i++)
    {
        Output_jarvis << input[i].x_pos() << " " << input[i].y_pos() << endl;
    }
    Output_jarvis << endl;
}

void DrawLines(const vector<Point> &output)
{
    // output to file
    fstream Output_jarvis;
    Output_jarvis.open("Output_jarvis.txt", ios::out | ios::app);

    // inside convex hull
    Output_jarvis << output.size() << endl;
    for (int i = 0; i < output.size(); i++)
    {
        Output_jarvis << output[i].x_pos() << " " << output[i].y_pos() << endl;
    }
}

int main()
{
    ifstream ifs;
    ifs.open("test.txt");

    int times;
    ifs >> times;

    vector<Point> input;
    vector<Point> output;

    for (int i = 0; i < times; i++)
    {
        double x, y;
        ifs >> x >> y;
        Point a = Point(x, y);
        input.push_back(a);
    }

    bruteForce(input, times);

    // create convex hull object
    ConvexHull convex;
    convex.FindConvexHull(input, output);

    removeEdgePoint(input, output);

    DrawPoints(input);
    DrawLines(output);

    return 0;
}