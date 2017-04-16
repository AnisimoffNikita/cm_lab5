#include "helpers.h"

#include <cmath>

int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

double bisection(double a, double b, const Func &f)
{
    constexpr double eps = 1e-6;
    double x = (a + b)*0.5;
    float check = f(x)*f(a);
    if (check != 0)
    {
        while (fabs(b-a) > eps*fabs(x) + eps)
        {
            if (check < 0)
                b = x;
            else
                a = x;
            x = (a + b)*0.5;
            check = f(x)*f(a);
        }
        return x;
    }
    else
    {
        if (f(x) == 0)
            return x;
        else
            return a;
    }
}
