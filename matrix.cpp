#include "matrix.h"


Matrix setMatrix(unsigned rows, unsigned cols)
{
    Matrix output(rows);
    for (unsigned i = 0; i < rows; i++)
    {
        output[i].resize(cols);
        std::fill(begin(output[i]), end(output[i]), 0);
    }
    return output;
}

void divide_row(Matrix &matrix, int row, double divider)
{
    int n = matrix.size();
    for (int i = 0; i < n + 1; i++)
    {
        matrix[row][i] /= divider;
    }
}

void add_row(Matrix &matrix, int row_to, int row_what, double multiplier)
{
    int n = matrix.size();
    for (int i = 0; i < n + 1; i++)
    {
        matrix[row_to][i] += multiplier*matrix[row_what][i];
    }
}

double sum_row(Matrix &matrix, int row)
{
    int n = matrix.size();
    double sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += matrix[row][i];
    }
    return sum;
}
