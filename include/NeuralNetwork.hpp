#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include "Matrix.hpp"
#include "ActivationFunction.hpp"

class NeuralNetwork {
public:
    NeuralNetwork(int input_nodes, int hidden_nodes, int output_nodes);

    Matrix predict(const Matrix& input);
    void train(const Matrix& input, const Matrix& target);

private:
    int input_nodes, hidden_nodes, output_nodes;

    Matrix weights_ih, weights_ho;
    Matrix bias_h, bias_o;

    double learning_rate = 0.1;
};

#endif // NEURALNETWORK_HPP
