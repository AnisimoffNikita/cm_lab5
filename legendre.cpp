#include "legendre.h"

#include <cmath>
#include "helpers.h"

Func legendrePolynom(int n)
{
    Vector coef(n + 1);
    coef[0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        double prev = coef[0];
        for (int j = 1; j < i; j++)
        {
            double tmp = coef[j];
            coef[j] = prev + coef[j];
            prev = tmp;
        }
        coef[i] = prev;
    }

    double factor = 1.0/(pow(2, n)*fact(n));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n; j++)
            coef[i] *= (n - i)*2 - j;
        coef[i] *= factor;
        if (i%2 != 0)
            coef[i] = -coef[i];
    }

    Func f = [coef = std::move(coef), n](double x)
    {
        double res = 0;
        for (int i = 0; i < n/2 + 1; i++)
            res += pow(x, n - i*2)*coef[i];
        return res;
    };

    return f;
}

Vector legendreRoots(int n)
{
    Func f = legendrePolynom(n);

    Vector t;
    t.reserve(n+1);

    constexpr double eps = 1e-6;
    double min = -1, max = 0;
    double k = 10;
    double dx = max-min;

    for (int i = 0; i < k; i++)
    {
        double a = min + dx*i/k;
        double b = min + dx*(i+1)/k;
        if (f(a)*f(b) <= 0)
        {
            double x = bisection(a, b, f);
            if (t.empty() || fabs(x - t.back()) > eps)
            {
                t.push_back(x);
                t.push_back(-x);
            }
        }
    }
    if (n%2 != 0)
        t.pop_back();

    return t;
}
