#include "Mixed.h"
using namespace std;

Mixed::Mixed(int a)
{
    Mixed::integer = a;
    Mixed::numerator = 0;
    Mixed::denominator = 0;
}

Mixed::Mixed(int a, int b, int c)
{
    Mixed::integer = a;
    Mixed::numerator = b;
    Mixed::denominator = c;
}

double Mixed::Evaluate()
{
    double tmp = (double)Mixed::numerator / Mixed::denominator;
    tmp += Mixed::integer;
    return tmp;
}

void Mixed::Simplify()
{
    int numTmp = Mixed::numerator;
    int denTmp = Mixed::denominator;
    int min;
    if (numTmp < 0 && denTmp > 0)
        min = denTmp;
    else if (numTmp > 0 && denTmp < 0)
        min = numTmp;
    else if (numTmp > 0 && denTmp > 0)
        min = numTmp > denTmp ? denTmp : numTmp;
    // std::cout << "min = " << min << endl;
    // if (numTmp > denTmp && denTmp > 0)
    //     min = denTmp;
    // else if (numTmp < denTmp && numTmp > 0)
    //     min = numTmp;
    // else
    //     min = numTmp;

    for (int i = 2; i <= min; i++)
    {
        if (numTmp % i == 0 && denTmp % i == 0 && numTmp != 0)
        {
            numTmp = numTmp / i;
            denTmp = denTmp / i;
            i = 1;
        }
        // std::cout << "here" << endl;
    }
    Mixed::numerator = numTmp;
    Mixed::denominator = denTmp;
}

void Mixed::ToFraction()
{
    int tmp = Mixed::integer;
    tmp = tmp * Mixed::denominator;
    if (tmp >= 0)
        Mixed::numerator += tmp;
    else
        Mixed::numerator = -(Mixed::numerator) + tmp;
    Mixed::integer = 0;
}

bool Mixed::operator<(const Mixed &a)
{
    double tmp = Mixed::Evaluate();
    Mixed newA = Mixed(a.integer, a.numerator, a.denominator);

    double aTmp = newA.Evaluate();

    if (tmp < aTmp)
        return true;
    else
        return false;
}

bool Mixed::operator>(const Mixed &a)
{
    double tmp = Mixed::Evaluate();
    Mixed newA = Mixed(a.integer, a.numerator, a.denominator);

    double aTmp = newA.Evaluate();

    if (tmp > aTmp)
        return true;
    else
        return false;
}

bool Mixed::operator<=(const Mixed &a)
{
    double tmp = Mixed::Evaluate();
    Mixed newA = Mixed(a.integer, a.numerator, a.denominator);

    double aTmp = newA.Evaluate();

    if (tmp <= aTmp)
        return true;
    else
        return false;
}

bool Mixed::operator>=(const Mixed &a)
{
    double tmp = Mixed::Evaluate();
    Mixed newA = Mixed(a.integer, a.numerator, a.denominator);

    double aTmp = newA.Evaluate();

    if (tmp >= aTmp)
        return true;
    else
        return false;
}

bool Mixed::operator==(const Mixed &a)
{
    double tmp = Mixed::Evaluate();
    Mixed newA = Mixed(a.integer, a.numerator, a.denominator);

    double aTmp = newA.Evaluate();

    if (tmp == aTmp)
        return true;
    else
        return false;
}

bool Mixed::operator!=(const Mixed &a)
{
    double tmp = Mixed::Evaluate();
    Mixed newA = Mixed(a.integer, a.numerator, a.denominator);

    double aTmp = newA.Evaluate();

    if (tmp != aTmp)
        return true;
    else
        return false;
}

Mixed Mixed::operator+(const Mixed &a)
{
    Mixed tmp = Mixed(Mixed::integer, Mixed::numerator, Mixed::denominator);
    Mixed aTmp = Mixed(a.integer, a.numerator, a.denominator);

    // 1 1/2 + 1 2/3
    if (Mixed::integer > 0 && a.integer > 0)
    {
        int newInt = Mixed::integer + a.integer;
        int newNum = Mixed::numerator * a.denominator + a.numerator * Mixed::denominator;
        int newDen = Mixed::denominator * a.denominator;
        if (newNum / newDen >= 1)
        {
            newInt += newNum / newDen;
            newNum -= (newNum / newDen) * newDen;
        }
        Mixed newMix = Mixed(newInt, newNum, newDen);
        return newMix;
    }
    // 1 1/2 + (-1 2/3)
    else if (Mixed::integer > 0 && a.integer < 0)
    {
        int newInt = Mixed::integer + a.integer;
        int newNum = Mixed::numerator * a.denominator - a.numerator * Mixed::denominator;
        int newDen = Mixed::denominator * a.denominator;
        Mixed newMix = Mixed(newInt, newNum, newDen);
        return newMix;
    }
    // (-1 1/2) + 1 2/3
    else if (Mixed::integer < 0 && a.integer > 0)
    {
        int newInt = Mixed::integer + a.integer;
        int newNum = -(Mixed::numerator * a.denominator) + a.numerator * Mixed::denominator;
        int newDen = Mixed::denominator * a.denominator;
        if (newNum < 0)
        {
            newInt--;
            newNum += +newDen;
        }
        Mixed newMix = Mixed(newInt, newNum, newDen);
        return newMix;
    }
    // (-1 1/3) + (-1 2/3)
    else if (Mixed::integer < 0 && a.integer < 0)
    {
        int newInt = Mixed::integer + a.integer;
        int newNum = Mixed::numerator * a.denominator + a.numerator * Mixed::denominator;
        int newDen = Mixed::denominator * a.denominator;
        if (newNum / newDen >= 1)
        {
            newInt -= newNum / newDen;
            newNum -= (newNum / newDen) * newDen;
        }
        Mixed newMix = Mixed(newInt, newNum, newDen);
        return newMix;
    }
    // 1 1 2 + (0 + or -)
    else if (Mixed::integer > 0 && a.integer == 0)
    {
        // (1 1/2) + (0 2/3)
        if (a.numerator >= 0)
        {
            int newInt = Mixed::integer;
            int newNum = Mixed::numerator * a.denominator + a.numerator * Mixed::denominator;
            int newDen = Mixed::denominator * a.denominator;
            if (newNum / newDen >= 1)
            {
                newInt += newNum / newDen;
                newNum -= (newNum / newDen) * newDen;
            }
            Mixed newMix = Mixed(newInt, newNum, newDen);
            return newMix;
        }
        // (1 1/2) + (0 -2/3)
        else
        {
            int newInt = Mixed::integer;
            int newNum = Mixed::numerator * a.denominator + a.numerator * Mixed::denominator;
            int newDen = Mixed::denominator * a.denominator;
            if (newNum < 0)
            {
                newInt--;
                newNum += newDen;
            }
            Mixed newMix = Mixed(newInt, newNum, newDen);
            return newMix;
        }
    }
    // (-1 1/2) + (0 + or -)
    else if (Mixed::integer < 0 && a.integer == 0)
    {
        // (-1 1/2) + (0 2/3)
        if (a.numerator >= 0)
        {
            int newInt = Mixed::integer;
            int newNum = Mixed::numerator * a.denominator + a.numerator * Mixed::denominator;
            int newDen = Mixed::denominator * a.denominator;
            if (newNum / newDen >= 1)
            {
                newInt++;
                newNum -= 2 * newDen;
            }
            Mixed newMix = Mixed(newInt, newNum, newDen);
            return newMix;
        }
        // (-1 1/2) + (0 -2/3)
        else
        {
            int newInt = Mixed::integer;
            int newNum = Mixed::numerator * a.denominator - a.numerator * Mixed::denominator;
            int newDen = Mixed::denominator * a.denominator;
            if (newNum / newDen >= 1)
            {
                newInt--;
                newNum -= newDen;
            }
            Mixed newMix = Mixed(newInt, newNum, newDen);
            return newMix;
        }
    }
    // (0 + or -) + (1 2/3)
    else if (Mixed::integer == 0 && a.integer > 0)
    {
        // (0 1/2) + (1 2/3)
        if (Mixed::numerator >= 0)
        {
            int newInt = a.integer;
            int newNum = Mixed::numerator * a.denominator + a.numerator * Mixed::denominator;
            int newDen = Mixed::denominator * a.denominator;
            if (newNum / newDen >= 1)
            {
                newInt++;
                newNum -= newDen;
            }
            Mixed newMix = Mixed(newInt, newNum, newDen);
            return newMix;
        }
        // (0 -1/2) + (1 2/3)
        else
        {
            int newInt = a.integer;
            int newNum = Mixed::numerator * a.denominator + a.numerator * Mixed::denominator;
            int newDen = Mixed::denominator * a.denominator;
            if (newNum < 0)
            {
                newInt--;
                newNum += newDen;
            }
            Mixed newMix = Mixed(newInt, newNum, newDen);
            return newMix;
        }
    }
    // (0 + or -) + (-1 2/3)
    else if (Mixed::integer == 0 && a.integer < 0)
    {
        // (0 1/2) + (-1 2/3)
        if (Mixed::numerator >= 0)
        {
            int newInt = a.integer;
            int newNum = Mixed::numerator * a.denominator - a.numerator * Mixed::denominator;
            int newDen = Mixed::denominator * a.denominator;
            if (newNum > 0)
            {
                newInt++;
                newNum -= 2 * newDen;
            }
            Mixed newMix = Mixed(newInt, newNum, newDen);
            return newMix;
        }
        // (0 -1/2) + (-1 2/3)
        else
        {
            int newInt = a.integer;
            int newNum = Mixed::numerator * a.denominator - a.numerator * Mixed::denominator;
            int newDen = Mixed::denominator * a.denominator;
            if (newNum / newDen <= -1)
            {
                newInt--;
                newNum += newDen;
                newNum = -(newNum);
            }
            Mixed newMix = Mixed(newInt, newNum, newDen);
            return newMix;
        }
    }
    // (0 + or -) + (0 + or -)
    else if (Mixed::integer == 0 && a.integer == 0)
    {
        // (0 1/2) + (0 2/3)
        if (Mixed::numerator >= 0 && a.numerator >= 0)
        {
            int newInt = 0;
            int newNum = Mixed::numerator * a.denominator + a.numerator * Mixed::denominator;
            int newDen = Mixed::denominator * a.denominator;
            if (newNum / newDen >= 1)
            {
                newInt++;
                newNum -= newDen;
            }
            Mixed newMix = Mixed(newInt, newNum, newDen);
            return newMix;
        }
        // (0 1/2) + (0 -2/3)
        else if (Mixed::numerator >= 0 && a.numerator < 0)
        {
            int newInt = 0;
            int newNum = Mixed::numerator * a.denominator + a.numerator * Mixed::denominator;
            int newDen = Mixed::denominator * a.denominator;
            Mixed newMix = Mixed(newInt, newNum, newDen);
            return newMix;
        }
        // (0 -1/2) + (0 2/3)
        else if (Mixed::numerator < 0 && a.numerator >= 0)
        {
            int newInt = 0;
            int newNum = Mixed::numerator * a.denominator + a.numerator * Mixed::denominator;
            int newDen = Mixed::denominator * a.denominator;
            Mixed newMix = Mixed(newInt, newNum, newDen);
            return newMix;
        }
        // (0 -1/2) + (0 -2/3)
        else
        {
            int newInt = 0;
            int newNum = -(Mixed::numerator * a.denominator) - (a.numerator * Mixed::denominator);
            int newDen = Mixed::denominator * a.denominator;
            if (newNum / newDen >= 1)
            {
                newInt--;
                newNum -= newDen;
            }
            Mixed newMix = Mixed(newInt, newNum, newDen);
            return newMix;
        }
    }
    return tmp;
}

Mixed Mixed::operator-(const Mixed &a)
{
    Mixed tmp = Mixed(Mixed::integer, Mixed::numerator, Mixed::denominator);

    // (1 1/2) - (1 2/3)
    if (Mixed::integer > 0 && a.integer > 0)
    {
        Mixed aTmp = Mixed(-a.integer, a.numerator, a.denominator);
        return tmp + aTmp;
    }
    // (1 1/2) - (-1 2/3)
    else if (Mixed::integer > 0 && a.integer < 0)
    {
        Mixed aTmp = Mixed(-a.integer, a.numerator, a.denominator);
        return tmp + aTmp;
    }
    // (-1 1/2) - (1 2/3)
    else if (Mixed::integer < 0 && a.integer > 0)
    {
        Mixed aTmp = Mixed(-a.integer, a.numerator, a.denominator);
        return tmp + aTmp;
    }
    // (-1 1/2) - (-1 2/3)
    else if (Mixed::integer < 0 && a.integer < 0)
    {
        Mixed aTmp = Mixed(-a.integer, a.numerator, a.denominator);
        return tmp + aTmp;
    }
    // (1 1 2) - (0 + or -)
    else if (Mixed::integer > 0 && a.integer == 0)
    {
        Mixed aTmp = Mixed(a.integer, -a.numerator, a.denominator);
        return tmp + aTmp;
    }
    // (-1 1/2) - (0 + or -)
    else if (Mixed::integer < 0 && a.integer == 0)
    {
        Mixed aTmp = Mixed(a.integer, -a.numerator, a.denominator);
        return tmp + aTmp;
    }
    // (0 + or -) - (1 2/3)
    else if (Mixed::integer == 0 && a.integer > 0)
    {
        Mixed aTmp = Mixed(-a.integer, a.numerator, a.denominator);
        return tmp + aTmp;
    }
    // (0 + or -) - (-1 2/3)
    else if (Mixed::integer == 0 && a.integer < 0)
    {
        Mixed aTmp = Mixed(-a.integer, a.numerator, a.denominator);
        return tmp + aTmp;
    }
    // (0 + or -) - (0 + or -)
    else if (Mixed::integer == 0 && a.integer == 0)
    {
        Mixed aTmp = Mixed(a.integer, -a.numerator, a.denominator);
        return tmp + aTmp;
    }

    int newInt = Mixed::integer - a.integer;
    int newNum = Mixed::numerator * a.denominator - a.numerator * Mixed::denominator;
    int newDen = Mixed::denominator * a.denominator;
    if (newNum / newDen < 0)
    {
        newInt--;
        newNum += newDen;
    }
    Mixed newMix = Mixed(newInt, newNum, newDen);
    return newMix;
}

Mixed Mixed::operator*(const Mixed &a)
{
    // (1 1/2) * (1 2/3)
    if (Mixed::integer > 0 && a.integer > 0)
    {
        int newInt = Mixed::integer * a.integer;
        int newNum = Mixed::integer * Mixed::denominator * a.numerator + a.integer * a.denominator * Mixed::numerator + Mixed::numerator * a.numerator;
        int newDen = Mixed::denominator * a.denominator;
        if (newNum / newDen > 0)
        {
            newInt += newNum / newDen;
            newNum -= (newNum / newDen) * newDen;
        }
        Mixed newMix = Mixed(newInt, newNum, newDen);
        newMix.Simplify();
        return newMix;
    }
    // (1 1/2) * (-1 2/3)
    else if (Mixed::integer > 0 && a.integer < 0)
    {
        int newInt = Mixed::integer * a.integer;
        int newNum = -(Mixed::integer * Mixed::denominator * a.numerator) + a.integer * a.denominator * Mixed::numerator - Mixed::numerator * a.numerator;
        int newDen = Mixed::denominator * a.denominator;
        if (newNum / newDen < 0)
        {
            newInt += newNum / newDen;
            newNum -= (newNum / newDen) * newDen;
            newNum = -(newNum);
        }
        Mixed newMix = Mixed(newInt, newNum, newDen);
        newMix.Simplify();
        return newMix;
    }
    // (-1 1/2) * (1 2/3)
    else if (Mixed::integer < 0 && a.integer > 0)
    {
        int newInt = Mixed::integer * a.integer;
        int newNum = Mixed::integer * Mixed::denominator * a.numerator - Mixed::numerator * a.numerator - Mixed::numerator * a.denominator * a.integer;
        int newDen = Mixed::denominator * a.denominator;
        std::cout << newNum << endl;
        if (newNum / newDen < 0)
        {
            newInt += newNum / newDen;
            newNum -= (newNum / newDen) * newDen;
            newNum = -(newNum);
        }
        Mixed newMix = Mixed(newInt, newNum, newDen);
        newMix.Simplify();
        return newMix;
    }
    // (-1 1/2) * (-1 2/3)
    else if (Mixed::integer < 0 && a.integer < 0)
    {
        int newInt = Mixed::integer * a.integer;
        int newNum = -(Mixed::integer * Mixed::denominator * a.numerator) - a.integer * a.denominator * Mixed::numerator + Mixed::numerator * a.numerator;
        int newDen = Mixed::denominator * a.denominator;
        if (newNum / newDen > 0)
        {
            newInt += newNum / newDen;
            newNum -= (newNum / newDen) * newDen;
        }
        Mixed newMix = Mixed(newInt, newNum, newDen);
        newMix.Simplify();
        return newMix;
    }
    // (0 1/2) * (1 2/3) or  or (0 -1/2) * (1 2/3)
    else if (Mixed::integer == 0 && a.integer > 0)
    {
        Mixed newMix = Mixed(a.integer, a.numerator, a.denominator);
        newMix.ToFraction();
        int newNum = Mixed::numerator * newMix.numerator;
        int newDen = Mixed::denominator * newMix.denominator;
        int newInt = newNum / newDen;
        if (newNum < 0)
        {
            newNum -= newInt * newDen;
            // newNum = -(newNum);
        }
        Mixed tmp = Mixed(newInt, newNum, newDen);
        return tmp;
    }
    // (0 1/2) * (-1 2/3) or (0 -1/2) * (-1 2/3)
    else if (Mixed::integer == 0 && a.integer < 0)
    {
        Mixed newMix = Mixed(a.integer, a.numerator, a.denominator);
        newMix.ToFraction();
        // std::cout << newMix << endl;
        int newNum = Mixed::numerator * newMix.numerator;
        int newDen = Mixed::denominator * newMix.denominator;
        int newInt = newNum / newDen;
        if (newNum / newDen < 0)
        {
            newNum -= newInt * newDen;
            newNum = -(newNum);
        }
        else if (newNum / newDen > 0)
        {
            newNum -= newInt * newDen;
        }
        Mixed tmp = Mixed(newInt, newNum, newDen);
        return tmp;
    }
    // (1 1/2) * (0 2/3) or (1 1/2) * (0 -2/3) or
    else if (Mixed::integer > 0 && a.integer == 0)
    {
        Mixed newMix = Mixed(Mixed::integer, Mixed::numerator, Mixed::denominator);
        newMix.ToFraction();
        int newNum = a.numerator * newMix.numerator;
        int newDen = a.denominator * newMix.denominator;
        int newInt = newNum / newDen;
        if (newNum / newDen < 0)
        {
            newNum -= newInt * newDen;
            newNum = -(newNum);
        }
        else if (newNum / newDen > 0)
        {
            newNum -= newInt * newDen;
        }
        Mixed tmp = Mixed(newInt, newNum, newDen);
        return tmp;
    }
    // (-1 1/2) * (0 2/3) or (-1 1/2) * (0 -2/3)
    else if (Mixed::integer < 0 && a.integer == 0)
    {
        Mixed newMix = Mixed(Mixed::integer, Mixed::numerator, Mixed::denominator);
        newMix.ToFraction();
        int newNum = a.numerator * newMix.numerator;
        int newDen = a.denominator * newMix.denominator;
        int newInt = newNum / newDen;
        if (newNum / newDen < 0)
        {
            newNum -= newInt * newDen;
            newNum = -(newNum);
        }
        else if (newNum / newDen > 0)
        {
            newNum -= newInt * newDen;
        }
        Mixed tmp = Mixed(newInt, newNum, newDen);
        return tmp;
    }
    // (0 1/2) * (0 2/3) or (0 1/2) * (0 -2/3) or (0 -1/2) * (0 2/3) or (0 -1/2) * (0 -2/3)
    else if (Mixed::integer == 0 && a.integer == 0)
    {
        int newInt = 0;
        int newNum = Mixed::numerator * a.numerator;
        int newDen = Mixed::denominator * a.denominator;
        Mixed newMix = Mixed(newInt, newNum, newDen);
        return newMix;
    }

    int newInt = Mixed::integer * a.integer;
    int newNum = Mixed::integer * Mixed::denominator * a.numerator + a.integer * a.denominator * Mixed::numerator + Mixed::numerator * a.numerator;
    int newDen = Mixed::denominator * a.denominator;
    Mixed newMix = Mixed(newInt, newNum, newDen);
    newMix.Simplify();
    return newMix;
}

Mixed Mixed::operator/(const Mixed &a)
{
    Mixed tmp = Mixed(Mixed::integer, Mixed::numerator, Mixed::denominator);
    Mixed aTmp = Mixed(a.integer, a.numerator, a.denominator);
    aTmp.ToFraction();
    int tmpNum = aTmp.denominator;
    int tmpDen = aTmp.numerator;
    Mixed newMix = Mixed(0, tmpNum, tmpDen);
    return tmp * newMix;
}
Mixed &Mixed::operator++()
{
    this->integer += 1;
    return *this;
}

const Mixed Mixed::operator++(int a)
{
    const Mixed old = (*this);
    this->integer++;
    return old;
}

Mixed &Mixed::operator--()
{
    this->integer -= 1;
    return *this;
}

const Mixed Mixed::operator--(int a)
{
    const Mixed newMix = (*this);
    this->integer--;
    return newMix;
}

istream &operator>>(istream &i, Mixed &a)
{
    while (1)
    {
        i >> a.integer >> a.numerator >> a.denominator;
        if ((a.integer != 0 || a.numerator != 0) && a.denominator == 0)
        {
            std::cout << "wrong type, please try again" << endl;
        }
        else if (a.integer < 0 && a.numerator < 0)
        {
            std::cout << "wrong type, please try again" << endl;
        }
        else if (a.numerator < 0 && a.denominator < 0)
        {
            std::cout << "wrong type, please try again" << endl;
        }
        else if (a.integer > 0 && a.numerator < 0)
        {
            std::cout << "wrong type, please try again" << endl;
        }
        else
        {
            break;
        }
    }

    return i;
}

ostream &operator<<(ostream &s, const Mixed &a)
{
    s << a.integer << " " << a.numerator << "/" << a.denominator << endl;
    return s;
}