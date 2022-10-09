-----------------------------------------------------------------------------
This program is to creat a binary tree, and at the end, the program will tell
the users whether it is a palindromic tree or not.

Firstly, the program inputs data from the file "treeNode.txt", and read a line
every time. Then uses the getWord() function to get every number in the line.
If the number is -1, then return, next time of insertion would on the right 
side. If the node has two "-1", then it is the leaf node of the tree.

After insertion, the program will call the isPalindromicTree() to show that 
it is palindromic tree or not.

Lastly, delete the tree.

Your input would be like:
3 1 -1 -1 1 -1 -1

this way,the tree would be like:
    3
   / \
  1   1

input:3 1 1 -1-1 2 -1 -1 1 2 -1 -1 1 -1 -1
tree:
        3
      /   \
     1     1
    / \   / \
   1   2 2   1

-----------------------------------------------------------------------------

1. 姓名: 龔鈺閎

2. 學號: 408410046

3. e-mail: yuhongg374@gmail.com

4. 完成的作業項目: main_tree.cpp, Tnode.cpp, Btree.cpp, makefile

5. Bouns內容(助教會依Bonus內容酌量給分): 
    無

6. Reference
   makefile: https://mropengate.blogspot.com/2018/01/makefile.html

