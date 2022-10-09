#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    fstream outputFile;
    // open the file into write-in mode, and if the file existed, then clean the file
    outputFile.open("cpp_output.txt", ios::out | ios::trunc);

    while (1)
    {
        double a = 0, b = 0, c = 0;
        double sum = 0.0;
        char space1, space2;

        std ::cout << "Please enter three sides:" << endl;
        std ::cin >> a >> b >> c;

        //  check the input file whether they are legal or not
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }

        if (a + b <= c || b + c <= a || a + c <= b)
        {
            outputFile << "The input data (" << a << "," << b << "," << c << ") is ilegal" << endl;
        }
        else
        {
            sum = (a + b + c) / 2;
            sum = sqrt(sum * (sum - a) * (sum - b) * (sum - c));
            outputFile << "The area of the triangle is " << sum << endl;
        }
    }

    return 0;
}
