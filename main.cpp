#include <iostream>
#include <cmath>

using namespace std;

#include "calculations.h"

int main()
{
    double a = 0.1;

    int n = 3;

    cout << "Input alpha: ";
    cin >> a;

    cout << "Input Legendre polynom order: ";
    cin >> n;

    double res = calculate(a, n);
    cout << "Result: " << res << endl;

    return 0;
}
