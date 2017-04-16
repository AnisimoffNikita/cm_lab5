#include "calculations.h"

#include <cmath>
#include <vector>

#include "gauss.h"
#include "legendre.h"
#include "function.h"
#include "helpers.h"

using namespace std;

double integrate(double a, double b, int n, const Func &f);

double calculate(double a, int n)
{
    Func f = [](double x)
    {
        return exp(-x*x/2);
    };

    Func F = [&f, a, n](double x)
    {
        return (1.0/sqrt(2*M_PI))*integrate(0, x, n, f) - a;
    };

    double res = bisection(0, 1, F);

    return res;
}

Vector calculateX(const Vector &t, double a, double b);
Vector calculateA(const Vector &t);

double integrate(double a, double b, int n, const Func &f)
{
    Vector t = legendreRoots(n);
    Vector A = calculateA(t);
    Vector x = calculateX(t, a, b);

    double res = 0;

    for (int i = 0; i < n; i++)
        res += A[i]*f(x[i]);

    res *= (b - a)/2;

    return res;
}

Vector calculateX(const Vector &t, double a, double b)
{
    Vector x(t.size());
    double apb2 = (a + b)/2;
    double bma2 = (b - a)/2;
    int n = t.size();
    for (int i = 0; i < n; i++)
        x[i] = bma2*t[i] + apb2;

    return x;
}


Vector calculateA(const Vector &t)
{
    int n = t.size();
    Matrix m = setMatrix(n, n + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            m[i][j] = pow(t[j], i);
        m[i][n] = i % 2 == 0 ? 2.0/(i + 1) : 0;
    }

    Vector res = gauss(m);

    return res;
}
