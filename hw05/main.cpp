// #include "Mixed.h"
// #include <string.h>

// int main()
// {
//     Mixed x(0, 0, 6), y(0, 1, 2), m1(0, -25, 4), m2(-1, 3, 4), m3(7), m4(0), m5;
//     cout << "Initial values: \nx = " << x << "\ny = " << y
//          << "\nm1 = " << m1 << "\nm2 = " << m2 << "\nm3 = " << m3
//          << "\nm4 = " << m4 << "\nm5 = " << m5 << "\n\n";
//     // Trying Simplify
//     x.Simplify();
//     y.Simplify();
//     m1.Simplify();
//     m2.Simplify();
//     m3.Simplify();
//     m4.Simplify();
//     m5.Simplify();
//     cout << "x simplified: " << x << endl
//          << "y simplified: " << y << endl
//          << "m1 simplified " << m1 << endl
//          << "m2 simplified " << m2 << endl
//          << "m3 simplified " << m3 << endl
//          << "m4 simplified " << m4 << endl
//          << "m5 simplified " << m5 << endl
//          << endl;
//     // Trying ToFraction
//     x.ToFraction();
//     y.ToFraction();
//     m1.ToFraction();
//     m2.ToFraction();
//     m3.ToFraction();
//     m4.ToFraction();
//     m5.ToFraction();
//     cout << "Values as fractions: \nx = " << x
//          << "\ny = " << y
//          << "\nm1 = " << m1 // demonstrate >> overload
//          << "\nm2 = " << m2
//          << "\nm3 = " << m3
//          << "\nm4 = " << m4
//          << "\nm5 = " << m5 << "\n\n";

//     while (1)
//     {
//         std::cout << "If you want to insert your own objects, please enter \"insert\", if you want to quit, please enter \"quit\" " << endl;
//         char line[16];
//         std::cin >> line;
//         if (strcmp(line, "insert") == 0)
//         {
//             Mixed x, y;
//             cout << "Enter first number: ";
//             cin >> x;
//             cout << "Enter second number: ";
//             cin >> y;
//             cout << "You entered:\n";
//             cout << " x = " << x << '\n';
//             cout << " y = " << y << '\n';
//             // demonstrate comparison overloads
//             if (x < y)
//                 cout << "(x < y) is TRUE\n";
//             if (x > y)
//                 cout << "(x > y) is TRUE\n";
//             if (x <= y)
//                 cout << "(x <= y) is TRUE\n";
//             if (x >= y)
//                 cout << "(x >= y) is TRUE\n";
//             if (x == y)
//                 cout << "(x == y) is TRUE\n";
//             if (x != y)
//                 cout << "(x != y) is TRUE\n"; // demonstrating Evaluate
//             cout << "\nDecimal equivalent of " << x << " is " << x.Evaluate() << '\n';
//             cout << "Decimal equivalent of " << y << " is " << y.Evaluate() << "\n\n";
//             // // demonstrating arithmetic overloads
//             cout << "(x + y) = " << x + y << '\n';
//             cout << "(x - y) = " << x - y << '\n';
//             cout << "(x * y) = " << x * y << '\n';
//             cout << "(x / y) = " << x / y << '\n';

//             //test x++,++x,x--,--x
//             Mixed xcopy = x++;
//             cout << "(xorigin) = " << xcopy << '\n'
//                  << "(x++) = " << x << '\n';
//             xcopy = ++x;
//             cout << "(xorigin) = " << xcopy << '\n'
//                  << "(++x) = " << x << '\n';
//             xcopy = x--;
//             cout << "(xorigin) = " << xcopy << '\n'
//                  << "(x--) = " << x << '\n';
//             xcopy = --x;
//             cout << "(xorigin) = " << xcopy << '\n'
//                  << "(--x) = " << x << '\n';
//         }
//         else if (strcmp(line, "quit") == 0)
//         {
//             break;
//         }
//         else
//         {
//             std::cout << "Please try again" << endl;
//         }
//     }

//     return 0;
// }

#include "Mixed.h"

int main()
{
    Mixed x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    cout << "You entered:\n";
    cout << " x = " << x << '\n';
    cout << " y = " << y << '\n';
    // demonstrate comparison overloads
    if (x < y)
        cout << "(x < y) is TRUE\n";
    if (x > y)
        cout << "(x > y) is TRUE\n";
    if (x <= y)
        cout << "(x <= y) is TRUE\n";
    if (x >= y)
        cout << "(x >= y) is TRUE\n";
    if (x == y)
        cout << "(x == y) is TRUE\n";
    if (x != y)
        cout << "(x != y) is TRUE\n"; // demonstrating Evaluate
    cout << "\nDecimal equivalent of " << x << " is " << x.Evaluate() << '\n';
    cout << "Decimal equivalent of " << y << " is " << y.Evaluate() << "\n\n";
    // // demonstrating arithmetic overloads
    cout << "(x + y) = " << x + y << '\n';
    cout << "(x - y) = " << x - y << '\n';
    cout << "(x * y) = " << x * y << '\n';
    cout << "(x / y) = " << x / y << '\n';
    // // demonstrating arithmetic that uses conversion constructor
    // // to convert the integer operand to a Mixed object
    cout << "(x + 2) = " << x + 2 << '\n'
         << "(x - 2) = " << x - 2 << '\n'
         << "(x * -2) = " << x * -2 << '\n'
         << "(x / 0) = " << x / 0 << '\n';

    //test x++,++x,x--,--x
    Mixed xcopy = x++;
    cout << "(xorigin) = " << xcopy << '\n'
         << "(x++) = " << x << '\n';
    xcopy = ++x;
    cout << "(xorigin) = " << xcopy << '\n'
         << "(++x) = " << x << '\n';
    xcopy = x--;
    cout << "(xorigin) = " << xcopy << '\n'
         << "(x--) = " << x << '\n';
    xcopy = --x;
    cout << "(xorigin) = " << xcopy << '\n'
         << "(--x) = " << x << '\n';
}
