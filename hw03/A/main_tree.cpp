#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Btree.cpp"
#define MAX 1024
#define maxWord 32
using namespace std;

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

void printTree(TnodePtr root)
{
    if (root != NULL)
    {
        printTree(root->left);
        std::cout << root->val << " ";
        printTree(root->right);
    }
}

void freeTree(TnodePtr root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
        return;
    }
}

int main()
{
    // file
    ifstream ifs;
    ifs.open("treeNode.txt");
    if (!ifs.is_open())
    {
        std::cout << "Failed to open file.\n";
        return 0;
    }

    // line buffer
    char buffer[MAX];

    // get line from file
    while (ifs.getline(buffer, sizeof(buffer)))
    {
        // create root node and stack(DFS use)
        TnodePtr root;
        TnodePtr stack[MAX];
        int visited[MAX] = {0};
        int stackTop = -1;

        // variables for getWord function
        char *ptr = buffer;
        char word[maxWord];
        int x;
        // get word and change it into integer
        while ((ptr = getWord(ptr, word)) != NULL)
        {
            x = atoi(word);
            // create new node and push into stack
            if (x != -1)
            {
                // create new node
                TnodePtr newNode = new Tnode;
                newNode->val = x;
                newNode->left = NULL;
                newNode->right = NULL;
                std::cout << "new node created" << endl;

                // Tree is empty
                if (stackTop == -1)
                {
                    root = newNode;
                    std::cout << "root node created" << endl;
                }
                // not empty, connect to the tree
                else
                {
                    TnodePtr tmp = stack[stackTop];

                    // insert at left
                    if (visited[stackTop] == 0)
                    {
                        tmp->left = newNode;
                        visited[stackTop] += -1;
                        std::cout << "link to the left side of the tree" << endl;
                    }
                    // insert at right
                    else if (visited[stackTop] == -1)
                    {
                        tmp->right = newNode;
                        visited[stackTop] += -1;
                        std::cout << "link to the right side of the tree" << endl;
                    }
                }

                // push to stack
                stack[++stackTop] = newNode;
            }
            // x is -1, update visited[] array and check if node at stack[top] has visited every child
            else if (x == -1)
            {
                if (visited[stackTop] == 0)
                {
                    std::cout << "left side is the end of the tree" << endl;
                }
                else if (visited[stackTop] == -1)
                {
                    std::cout << "both side is the end of the tree" << endl;
                }
                visited[stackTop] += x;
                // leaf node, then pop out from stack
                while (visited[stackTop] == -2)
                {
                    visited[stackTop] = 0;
                    stackTop--;
                }
            }
        }
        // check the tree if it is a palindromic tree or not
        Btree *tree = new Btree(root);
        // is palindromic tree
        if (tree->isPalindromicTree() == true)
        {
            std::cout << "It is palindromic tree" << endl;
        }
        // is not a palindromic tree
        else
        {
            std::cout << "It is not a palindromic tree" << endl;
        }

        // at the end, print out the tree by in-order-traversal
        std::cout << "print the tree by in-order-traversal: ";
        printTree(root);
        std::cout << endl;

        // delete the tree
        freeTree(root);
        delete tree;
    }

    // close file
    ifs.close();

    return 0;
}