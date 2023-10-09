#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(int input_nodes, int hidden_nodes, int output_nodes)
    : input_nodes(input_nodes), hidden_nodes(hidden_nodes), output_nodes(output_nodes) {
    weights_ih = Matrix(hidden_nodes, input_nodes);  // Random initialization can be added
    weights_ho = Matrix(output_nodes, hidden_nodes);
    bias_h = Matrix(hidden_nodes, 1);
    bias_o = Matrix(output_nodes, 1);
}

Matrix NeuralNetwork::predict(const Matrix& input) {
    // Calculate hidden outputs
    Matrix hidden = weights_ih * input;
    hidden += bias_h;
    hidden.applyFunction(sigmoid);

    // Calculate the output
    Matrix output = weights_ho * hidden;
    output += bias_o;
    output.applyFunction(sigmoid);

    return output;
}

void NeuralNetwork::train(const Matrix& input, const Matrix& target) {
    // Forward pass
    Matrix hidden = weights_ih * input;
    hidden += bias_h;
    hidden.applyFunction(sigmoid);

    Matrix output = weights_ho * hidden;
    output += bias_o;
    output.applyFunction(sigmoid);

    // Backpropagation
    // Calculate output errors (target - output)
    Matrix output_errors = target - output;

    // Calculate gradient
    Matrix gradient = output;
    gradient.applyFunction(sigmoid_derivative);
    gradient *= output_errors;
    gradient *= learning_rate;

    // Calculate hidden -> output deltas
    Matrix hidden_T = hidden.transpose();
    Matrix weight_ho_deltas = gradient * hidden_T;

    weights_ho += weight_ho_deltas;
    bias_o += gradient;

    // Calculate hidden errors
    Matrix weights_ho_T = weights_ho.transpose();
    Matrix hidden_errors = weights_ho_T * output_errors;

    // Calculate input -> hidden gradient
    Matrix hidden_gradient = hidden;
    hidden_gradient.applyFunction(sigmoid_derivative);
    hidden_gradient *= hidden_errors;
    hidden_gradient *= learning_rate;

    Matrix input_T = input.transpose();
    Matrix weight_ih_deltas = hidden_gradient * input_T;

    weights_ih += weight_ih_deltas;
    bias_h += hidden_gradient;
}
