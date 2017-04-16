#include <iostream>
#include <cmath>

using namespace std;

#include "calculations.h"

int main()
{
    double a = 0.3;

    int n = 3;

    cout << "Input alpha: ";
    cin >> a;

    cout << "Input Legendre polynom order (-1 to stop): ";
    cin >> n;

    while (n != -1)
    {
        double res = calculate(a, n);
        cout << "Result: " << res << endl;

        cout << "Input alpha: ";
        cin >> a;

        cout << "Input Legendre polynom order: ";
        cin >> n;
    }



    return 0;
}
