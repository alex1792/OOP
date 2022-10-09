#include <iostream>
#include "Tnode.cpp"
using namespace std;

class Btree
{
private:
    TnodePtr root;
    bool areMirrors(TnodePtr root1, TnodePtr root2)
    {
        /* If either tree is empty, both must be.
                       ---- to be filled -----*/
        if (root1 == NULL && root2 == NULL)
        {
            std::cout << "reach the end" << endl;
            return true;
        }
        else if (root1 == NULL || root2 == NULL)
        {
            std::cout << "one side is NULL" << endl;
            return false;
        }
        /*Neither tree is empty. The roots must have equal values.
            --------------- to be filled ---------------*/
        if (root1->val != root2->val)
        {
            std::cout << "different value, tree is not palidromic tree" << endl;
            return false;
        }
        /*To see if they are mirrors, we need to check whether the left
        sub-tree of the first tree mirrors the right sub-tree of the second tree
        and vice-versa. 
        --------------- // to be filled ---------------*/
        // head node
        else if (root1 == root2)
        {
            std::cout << "head node" << endl;
            return areMirrors(root1->left, root1->right);
        }
        // other node
        else
        {
            std::cout << "same value: " << root1->val << endl;
            if (areMirrors(root1->left, root2->right) == true)
            {
                return areMirrors(root1->right, root2->left);
            }
            return false;
            // return areMirrors(root1->right, root2->left);
        }
        // return true;
    }

public:
    bool isPalindromicTree()
    {
        return areMirrors(root, root);
    }
    Btree(TnodePtr rootNode)
    {
        root = rootNode;
    }
};
