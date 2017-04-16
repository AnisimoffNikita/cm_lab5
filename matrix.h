#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using namespace std;

using Matrix = vector<vector<double>>;
using Vector = vector<double>;
Matrix setMatrix(unsigned rows, unsigned cols);

void divide_row(Matrix &matrix, int row, double divider);
void add_row(Matrix &matrix, int row_from, int row_to, double multiplier);
double sum_row(Matrix &matrix, int row);
#endif // MATRIX_H
