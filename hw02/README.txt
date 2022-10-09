-----------------------------------------------------------------------------
The program is used to compute the derivative of the function. First, 
users enter the number of X so later the program will compute the value
of f(x) and f'(x). Secondly, users enter a line, first number is the 
highest power of the function, and the rest are the coefficients, start
from the lowest power to the highest power. Each number is separated by
a white space ' '. After input, the program will print out f(x) and f'(x)
and their value. Lastly, if the user want to keep running the program, they
should input "1", if not, the program will be terminated.

The solving logic of the program is to use getline() function to get a line
from the file, then use the getWord() function to deal with strings. After
getWord(), then use stof() to change the data type from string to float.

Here are some examples of input and output:

input:
1               // the value of X                                   (from user)
3 1 2 3 4       // highest power of the function and coefficients   (from polydata.txt)
1               // continue                                         (from user)
3               // the value of X                                   (from user)
3 1 2 3 4       // highest power of the function and coefficients   (from polydata.txt)
1               // continue                                         (from user)
1               // the value of X                                   (from user)
3 1 0 0 0       // highest power of the function and coefficients   (from polydata.txt)
1               // continue                                         (from user)
0               // the value of X                                   (from user)
5 3 0 0 0 0 1   // highest power of the function and coefficients   (from polydata.txt)
1               // continue                                         (from user)
1               // the value of X                                   (from user)
3 5 -2 4 1      // highest power of the function and coefficients   (from polydata.txt)
1               // continue                                         (from user)
1               // the value of X                                   (from user)
3 0 1 2 c       // highest power of the function and coefficients   (from polydata.txt)
0               // program terminated                               (from user)


output:
Please enter the value of x:
1
f(x) = 1 + 2*x + 3*x*x + 4*x*x*x
f'(x) = 2 + 6*x + 12*x*x
f(1) = 10
f'(1) = 20
If you want to keep going, please enter 1
1
Please enter the value of x:
3
f(x) = 1 + 2*x + 3*x*x + 4*x*x*x
f'(x) = 2 + 6*x + 12*x*x
f(3) = 142
f'(3) = 128
If you want to keep going, please enter 1
1
Please enter the value of x:
1
f(x) = 1
f'(x) = 0
f(1) = 1
f'(1) = 0
If you want to keep going, please enter 1
1
Please enter the value of x:
0
f(x) = 3 + 1*x*x*x*x*x
f'(x) = 5*x*x*x*x
f(0) = 3
f'(0) = 0
If you want to keep going, please enter 1
1
Please enter the value of x:
1
f(x) = 5 + (-2)*x + 4*x*x + 1*x*x*x
f'(x) = (-2) + 8*x + 3*x*x
f(1) = 8
f'(1) = 9
If you want to keep going, please enter 1
1
Please enter the value of x:
1
Syntax Error, please check your test data!
program terminate!

note:
the sample input is given in the .zip file, called test1
-----------------------------------------------------------------------------

1. 姓名: 龔鈺閎

2. 學號: 408410046

3. e-mail: yuhongg374@gmail.com

4. 完成的作業項目: C++, makefile

5. Bouns內容(助教會依Bonus內容酌量給分): 
    無

6. Reference
    C++:
        讀檔: https://shengyu7697.github.io/blog/2021/01/25/Cpp-read-text-file/
        string to float :http://www.cplusplus.com/reference/string/stof/

