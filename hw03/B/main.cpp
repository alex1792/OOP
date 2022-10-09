#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
// #include "Polygon.cpp"
#include "isEdgeIntersect.cpp"

char *getWord(char *line, char *word)
{
    char *ptr = line;
    char *qtr = word;
    while (isspace(*ptr))
    {
        *ptr++;
    }
    while (!isspace(*ptr) && *ptr != '\0')
    {
        *qtr++ = *ptr++;
    }
    *qtr = '\0';
    if (strlen(word) == 0)
    {
        return NULL;
    }
    else
    {
        return ptr;
    }
}

int main()
{
    // open file
    ifstream fs;
    fs.open("polydata.txt");

    int listCnt = 0;
    char line[1024];

    // 2 Linked List to save datas
    LinkedList list1, list2;

    // read from file
    while (fs.getline(line, 1024))
    {
        char *ptr = line;
        char word[32];

        ptr = getWord(ptr, word);
        int mode = atoi(word);
        if (mode == -1)
        {
            std::cout << "end of insertion" << endl;
            // Point tmp = list1.getCurrentPoint();
            // std::cout << "in main() reaches -1, current_pointer of a: " << tmp.x << "," << tmp.y << endl;
            listCnt++;
            continue;
        }

        // new point to save the x and y coordinates
        Point point;

        // get x coordinate of the point
        ptr = getWord(ptr, word);
        point.x = atoi(word);

        // get y coordinate of the point
        ptr = getWord(ptr, word);
        point.y = atoi(word);

        // insert at head
        if (mode == 1)
        {
            if (listCnt == 0)
            {
                list1.insertToPrev(point);
            }
            else if (listCnt == 1)
            {
                list2.insertToPrev(point);
            }

            // nodeCnt++;
        }
        // insert next
        else if (mode == 2)
        {
            if (listCnt == 0)
            {
                list1.insertToNext(point);
            }
            else if (listCnt == 1)
            {
                list2.insertToNext(point);
            }

            // nodeCnt++;
        }
        else
        {
            std::cout << "wrong format, please try again" << endl;
        }
    }

    int listLen = list1.getSize();
    std::cout << "Polygon a:" << endl;
    for (int i = 0; i < listLen; i++)
    {
        Point tmp = list1.getCurrentPoint();
        std::cout << tmp.x << "," << tmp.y << endl;
        list1.pointToNext();
    }
    listLen = list2.getSize();
    std::cout << "Polygon b:" << endl;
    for (int i = 0; i < listLen; i++)
    {
        Point tmp = list2.getCurrentPoint();
        std::cout << tmp.x << "," << tmp.y << endl;
        list2.pointToNext();
    }

    // create two pologon and a split_polygon of polygon a
    Polygon a, b;

    //  get the array of point of linked list 1
    int list_1_Size = list1.getSize();
    Point ptArray1[list_1_Size + 1];
    for (int i = 0; i < list_1_Size; i++)
    {
        ptArray1[i] = list1.getCurrentPoint();
        list1.pointToNext();
    }

    //  get the array of points of linked list 2
    int list_2_Size = list2.getSize();
    Point ptArray2[list_2_Size + 1];
    for (int i = 0; i < list_2_Size; i++)
    {
        ptArray2[i] = list2.getCurrentPoint();
        list2.pointToNext();
    }

    // set points into polygon
    a.setPolygon(ptArray1, list_1_Size);
    b.setPolygon(ptArray2, list_2_Size);

    // Point tmp = list1.getCurrentPoint();
    // std::cout << "current_pointer before split: ";
    // std::cout << tmp.x << "," << tmp.y << endl;
    // list1.pointToNext();
    // tmp = list1.getCurrentPoint();
    // std::cout << "current_pointer before split: ";
    // std::cout << tmp.x << "," << tmp.y << endl;

    // list1.pointToNext();

    // create the split_polygon of a
    Polygon *copy_a = NULL;
    copy_a = a.splitPolygon();

    // check polygon a and b whether they collide or not
    if (b.isCollide(a) == true)
    {
        std::cout << "a and b does not collide..." << endl;
    }
    else
    {
        std::cout << "a and b encouter collision..." << endl;
    }

    // check split_polygon and polygon b, whether they collide or not
    if (copy_a->isCollide(b) == true)
    {
        std::cout << "copy_a and b does not collide..." << endl;
    }
    else
    {
        std::cout << "copy_a and b encounter collision..." << endl;
    }

    // close file
    fs.close();

    return 0;
}