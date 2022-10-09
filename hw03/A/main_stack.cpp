#include <iostream>
#include <string>
#include <string.h>
// #include "Node.cpp"
#include "Stack.cpp"
using namespace std;

int main()
{
    stack *s1 = new stack();
    int i;

    while (1)
    {
        int mode;
        std::cout << "Please enter the mode" << endl;
        std::cin >> mode;

        // push
        if (mode == 1)
        {
            int data;
            std::cout << "Please enter the data you want to push: ";
            std::cin >> data;
            s1->push(data);
        }
        // pop
        else if (mode == 2)
        {
            s1->pop();
        }
        // empty
        else if (mode == 3)
        {
            s1->empty();
        }
        // exit
        else if (mode == -1)
        {
            break;
        }
        // wrong format, print the usage
        else
        {
            std::cout << "Syntax error. Please try again" << endl;
            std::cout << "1 -> push" << endl;
            std::cout << "2 -> pop" << endl;
            std::cout << "3 -> empty" << endl;
            std::cout << "-1 -> quit" << endl;
        }
    }

    int ret = 1;
    while (ret != 0)
    {
        // std::cout << "pop out all elements in stack" << endl;
        ret = s1->pop();
    }

    delete s1;

    return 0;
}