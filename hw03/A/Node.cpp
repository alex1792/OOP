#include <iostream>
using namespace std;

class node
{
public:
    int item;
    node *next;
    node(int x, node *t)
    {
        item = x;
        next = t;
    }
};

typedef node *nodePtr;