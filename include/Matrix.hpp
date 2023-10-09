#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <cmath> // for activation functions

class Matrix {
public:
    Matrix(int rows, int cols);
    double& operator()(int i, int j);
    const double& operator()(int i, int j) const;
    
    // Add other matrix operations (e.g., addition, multiplication)
    void applyFunction(double (*func)(double));

    int rows, cols;
    std::vector<std::vector<double>> data;
};

#endif // MATRIX_HPP
