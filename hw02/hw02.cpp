#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;
#define wordSize 16

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

int isAlpah(char *word)
{
    char *ptr = word;
    // std ::cout << word << endl;
    while (*ptr != '\0')
    {
        // a ~ z or A ~ Z
        if ((*ptr - 'a' >= 0 && *ptr - 'z' <= 0) || (*ptr - 'A' >= 0 && *ptr - 'Z' <= 0))
        {
            return 1;
        }
        ptr++;
    }
    return 0;
}

int highestPower(float coef[])
{
    for (int i = coef[0] + 1; i > 0; i--)
    {
        if (coef[i] != 0)
        {
            return i - 1;
        }
    }
    return 0;
}

void display(int power, float coef[])
{
    if (power <= 0)
    {
        std ::cout << coef[1] << endl;
        return;
    }
    for (int i = 1; i <= power + 1; i++)
    {
        if (coef[i] == 0)
        {
            continue;
        }
        // if coefficient is smaller than 0 print ()
        if (coef[i] < 0)
        {
            std::cout << '(';
        }
        std ::cout << coef[i];
        if (coef[i] < 0)
        {
            std::cout << ')';
        }
        for (int j = 1; j < i; j++)
        {
            std ::cout << "*x";
        }
        if (i <= power)
        {
            std ::cout << " + ";
        }
    }
    std ::cout << endl;
}

void derivative(int power, float coef[], float dev_coef[])
{
    for (int i = 2; i <= power + 1; i++)
    {
        dev_coef[i - 1] = coef[i] * (i - 1);
    }
}

float compute(int power, float coef[], float x)
{
    float ret = 0;
    for (int i = 1; i <= power + 1; i++)
    {
        float tmp = coef[i];
        for (int j = 2; j <= i; j++)
        {
            tmp = tmp * x;
        }
        ret += tmp;
    }
    return ret;
}

int main()
{
    // file
    ifstream ifs;
    char buffer[256] = {0};

    // open file
    ifs.open("polydata.txt");
    if (!ifs.is_open())
    {
        cout << "Failed to open file.\n";
        return 0;
    }

    while (1)
    {

        // can get a line from the file successfully
        if (ifs.getline(buffer, sizeof(buffer)))
        {
            // input the value of x
            float x;
            std ::cout << "Please enter the value of x:" << endl;
            std ::cin >> x;

            // input the highest power and coefficient of the function
            float coef[7];
            // initialize the array
            for (int i = 0; i < 7; i++)
            {
                coef[i] = 0.0;
            }

            // syntax error
            // std ::cout << "buffer :" << buffer << endl;
            if (isAlpah(buffer) == 1)
            {
                std ::cout << "Syntax Error, please check your test data!" << endl;
                continue;
            }

            char *ptr = buffer;
            char word[wordSize];
            int idx = 0;

            while ((ptr = getWord(ptr, word)) != NULL)
            {
                coef[idx] = std::stof(word);

                if (idx == coef[0] + 1)
                {
                    break;
                }
                idx++;
            }

            // get the highest power
            int power = highestPower(coef);
            // std ::cout << "power: " << power << endl;

            // display the function
            std ::cout << "f(x) = ";
            display(power, coef);

            // get the derivative of the function and display it
            float dev_coef[6];
            for (int i = 0; i < 6; i++)
            {
                dev_coef[i] = 0.0;
            }
            derivative(power, coef, dev_coef);
            std ::cout << "f'(x) = ";
            display(power - 1, dev_coef);

            // compute the value of f(x) and f'(x)
            float ret = compute(power, coef, x);
            std ::cout << "f(" << x << ") = " << ret << endl;
            ret = compute(power - 1, dev_coef, x);
            std ::cout << "f'(" << x << ") = " << ret << endl;

            // check if the user wants to continue running the program
            std ::cout << "If you want to keep going, please enter 1\n";
            std ::cin >> x;
            if (x != 1)
            {
                std ::cout << "program terminate!" << endl;
                break;
            }
        }
        // reach the end of the file, program terminated
        else
        {
            std ::cout << "End of file! Program terminated!" << endl;
            break;
        }
    }
    // close file
    ifs.close();
    return 0;
}
