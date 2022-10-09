#include <iostream>
using namespace std;

struct Point
{
    int x; // x−coordinate
    int y; // y−coordinate
};
struct Node
{
    Point pt;
    Node *next, *prev;
};

class LinkedList
{
public:
    LinkedList();  // constructor
    ~LinkedList(); // destructor
    // Please add an informative message in constructor and destructor:
    // cout << “Constructing LinkedList…” << endl;
    // cout << “Deleting LinkedList…” << endl;
    int getSize() const;
    // return the number of elements (node) of the linked list
    bool isEmpty() const;     // return true if the list is empty
    void clear();             // make the circular doubly linked list empty
    void deleteCurrentNode(); // delete the current node. The current
    // pointer will point to the next node of the deleted node
    void pointToNext();
    // make the current_pointer point to the next node
    void pointToPrev();
    // make the current_pointer point to the previous node
    Point getCurrentPoint() const;
    // return the Point pointed by the current_pointer
    void insertToNext(const Point &pt);
    // insert a Point next to the current node
    void insertToPrev(const Point &pt);
    // insert a Point before the current node
private:
    // The current pointer. It points to the current node.
    // If the linked list is empty, it equals to NULL.
    Node *current_pointer;
};

// constructor
LinkedList::LinkedList()
{
    std::cout << "Constructing LinkedList..." << endl;
    current_pointer = NULL;
}

// destructor
LinkedList::~LinkedList()
{
    // Please add an informative message in constructor and destructor:
    // cout << “Constructing LinkedList…” << endl;
    std::cout << "Deleting LinkedList…" << endl;
    // clear();
}

// return the number of elements(node) of the linked list
int LinkedList::getSize() const
{
    int nodeCnt = 0;
    Node *tmp = current_pointer;
    if (isEmpty())
    {
        return 0;
    }
    while (1)
    {
        // std::cout << "in while loop..." << endl;
        nodeCnt++;
        // if (tmp->next == current_pointer)
        // {
        //     break;
        // }
        tmp = tmp->next;
        if (tmp == current_pointer)
        {
            return nodeCnt;
        }
    }
    return nodeCnt;
}

// return true if the list is empty
bool LinkedList::isEmpty() const
{
    if (current_pointer == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// delete the current node. The current
void LinkedList::clear()
{
    if (current_pointer == NULL)
    {
        return;
    }
    Node *tmp = current_pointer;
    while (tmp->next != current_pointer)
    {
        Node *deletedNode = tmp;
        delete deletedNode;
        tmp = tmp->next;
    }
    delete tmp;
    // std::cout << "LinkedList clear..." << endl;
    current_pointer = NULL;
}

// pointer will point to the next node of the deleted node
void LinkedList::deleteCurrentNode()
{
    current_pointer->prev->next = current_pointer->next;
    current_pointer->next->prev = current_pointer->prev;
    Node *tmp = current_pointer;
    current_pointer = tmp->next;
    delete tmp;
}

// make the current_pointer point to the next node
void LinkedList::pointToNext()
{
    Node *tmp = current_pointer;
    tmp = tmp->next;
    current_pointer = tmp;
    // std::cout << "point to next..." << endl;
}

// make the current_pointer point to the previous node
void LinkedList::pointToPrev()
{
    Node *tmp = current_pointer;
    tmp = tmp->prev;
    current_pointer = tmp;
    // std::cout << "point to prev..." << endl;
}

// return the Point pointed by the current_pointer
Point LinkedList::getCurrentPoint() const
{
    return current_pointer->pt;
}

// insert a Point next to the current node
void LinkedList::insertToNext(const Point &pt)
{
    // if linked list is empty
    if (isEmpty())
    {
        Node *newNode = new Node;
        newNode->pt = pt;
        newNode->next = newNode;
        newNode->prev = newNode;
        current_pointer = newNode;
        return;
    }

    // link next to the current_point
    Node *newNode = new Node;
    newNode->pt = pt;
    newNode->next = current_pointer->next;
    current_pointer->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = current_pointer;
    pointToNext();
}

// insert a Point before the current node
void LinkedList::insertToPrev(const Point &pt)
{
    // if linked list is empty
    if (isEmpty())
    {
        Node *newNode = new Node;
        newNode->pt = pt;
        newNode->next = newNode;
        newNode->prev = newNode;
        current_pointer = newNode;
        std::cout << "Insert first node in prev()..." << endl;
        return;
    }

    // link in front of current_pointer's node
    Node *newNode = new Node;
    newNode->pt = pt;
    current_pointer->prev->next = newNode;
    newNode->prev = current_pointer->prev;
    current_pointer->prev = newNode;
    newNode->next = current_pointer;
    // std::cout << "Insert before current node..." << endl;
    pointToPrev();
}
