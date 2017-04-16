#include "gauss.h"

#include <cmath>


Vector gauss(Matrix &matrix)
{
    int n = matrix.size();
    Vector result(n);

    triangular_matrix(matrix);

    for (int i = n - 1; i >= 0; i--)
    {
        double x = matrix[i][n];
        for (int j = i + 1; j < n; j++)
        {
            x -= matrix[i][j]*result[j];
        }
        result[i] = x;
    }
    return result;
}


void triangular_matrix(Matrix &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        divide_row(matrix, i, matrix[i][i]);

        for (int j = i + 1; j < n; j++)
        {
            add_row(matrix, j, i, -matrix[j][i]);
        }
    }
}
