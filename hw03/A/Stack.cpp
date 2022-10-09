#include <iostream>
#include "Node.cpp"
using namespace std;
#define SIZE 10

class stack
{
private:
    nodePtr top;

public:
    stack() { top = 0; }
    void empty() const
    {
        if (top == 0)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    void push(int element);
    int pop();
};

void stack::push(int x)
{
    nodePtr newNode = new node(x, NULL);
    nodePtr tmp = top;
    std::cout << "new node built" << endl;

    if (top == 0)
    {
        std::cout << "Linked list is empty" << endl;
        top = newNode;
        std::cout << "new element insert into linked list" << endl;
        return;
    }

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    std::cout << "new element insert into linked list" << endl;
}

int stack::pop()
{
    // int ret;
    nodePtr tmp = top;
    nodePtr cur = tmp;

    // linked list is empty
    if (tmp == 0)
    {
        return 0;
    }

    while (tmp->next != NULL)
    {
        cur = tmp;
        tmp = tmp->next;
    }
    // pop the head node, list is going to be empty
    if (cur == tmp)
    {
        // ret = tmp->item;
        top = 0;
        std::cout << "pop out from stack: " << tmp->item << endl;
        delete tmp;
        return 0;
    }
    // not the head node, still remain nodes in linked list
    else
    {
        // ret = tmp->item;
        cur->next = NULL;
        std::cout << "pop out from stack: " << tmp->item << endl;
        delete tmp;
        return 1;
    }

    // std::cout << "pop out from stack: " << tmp->item << endl;
    // delete tmp;
    // return ret;
}