#ifndef Mixed_Header
#define Mixed_Header

#include <iostream>
#include <iomanip>
using namespace std;
// #include <stdlib.h>

class Mixed
{
private:
    int integer;
    int numerator;
    int denominator;

public:
    // constructor
    Mixed(int = 0);       // set object to the value of parameter, and has no fraction part
    Mixed(int, int, int); // set object follow the integer, numerator, and denominator order
    /* more detail about the setting rules, please check Hw5 pdf page 3 */
    // member function
    double Evaluate(); // return the decimal equivalent of the Mixed number
    void Simplify();   // simplify the Mixed number representation to lowest terms. (This means that the fraction part should be reduced to lowest terms, and the fraction part should not be an improper fraction)
    void ToFraction(); // convert the mixed number to into fraction form. (This means integer part is 0, and the fraction portion may be an improper fraction)
    /* more detail about the member function description, please check Hw5 pdf page 5 - 6*/
    // operator overloading
    bool operator<(const Mixed &);
    bool operator>(const Mixed &);
    bool operator<=(const Mixed &);
    bool operator>=(const Mixed &);
    bool operator==(const Mixed &);
    bool operator!=(const Mixed &);
    Mixed operator+(const Mixed &);
    Mixed operator-(const Mixed &);
    Mixed operator*(const Mixed &);
    Mixed operator/(const Mixed &);
    Mixed &operator++();
    const Mixed operator++(int);
    Mixed &operator--();
    const Mixed operator--(int);
    // friend function
    friend istream &operator>>(istream &, Mixed &);       // The input format for a Mixed number object will be: integer numerator/denominator(notice that there has a '/'), all parts are all of type int.
    friend ostream &operator<<(ostream &, const Mixed &); // This should output the Mixed number in the same format as above
    /* more detail about the operator>> and operator<<, please check Hw5 pdf page 7 - 9*/
    /* All the operator overloading functions should work as we usually think; for instance, A++ means A = A + 1 , the denominator part should not be 0 when doing division*/
};

#endif // Mixed_Header