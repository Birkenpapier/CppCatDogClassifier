#include "Matrix.hpp"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data.resize(rows, std::vector<double>(cols, 0.0));
}

double& Matrix::operator()(int i, int j) {
    return data[i][j];
}

const double& Matrix::operator()(int i, int j) const {
    return data[i][j];
}

void Matrix::applyFunction(double (*func)(double)) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = func(data[i][j]);
        }
    }
}
