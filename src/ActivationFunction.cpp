#include "ActivationFunction.hpp"

double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

double sigmoid_derivative(double x) {
    return x * (1.0 - x); // assumes x is already the sigmoid output
}
