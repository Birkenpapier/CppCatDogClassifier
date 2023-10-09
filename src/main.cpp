#include "NeuralNetwork.hpp"
#include "Matrix.hpp"
#include "ActivationFunction.hpp"
#include <iostream>

// Assuming these functions are declared in LoadImages.cpp and you've included their prototypes in some header
Matrix loadImageToMatrix(const std::string& filepath);
Matrix loadLabel(const std::string& filepath);

int main() {
    // Define constants
    const int inputNodes = 28 * 28;  // image size: 28x28 pixels
    const int hiddenNodes = 128;     // an arbitrary number, can be tuned
    const int outputNodes = 2;       // 2 output classes: cat and dog
    const int epochs = 1000;         // number of training iterations

    // Initialize neural network
    NeuralNetwork nn(inputNodes, hiddenNodes, outputNodes);

    // Training loop
    for (int i = 0; i < epochs; ++i) {
        // Here's an example for a single image. In practice, you'd loop through your entire dataset.
        // Ensure to replace 'cat1.bmp' and 'cat1.txt' with relevant file names or use a loop to cycle through filenames.
        Matrix input = loadImageToMatrix("data/images/cat1.bmp");
        Matrix target = loadLabel("data/labels/cat1.txt");

        nn.train(input, target);

        // Every 10 epochs, print a prediction (just for testing and demonstration purposes)
        if (i % 10 == 0) {
            Matrix prediction = nn.predict(input);

            // Print the prediction (you can format this to be more readable or decipherable)
            std::cout << "Prediction after epoch " << i << ":\n";
            prediction.print();  // Assuming there's a print function for the Matrix class
            std::cout << "------------" << std::endl;
        }
    }

    return 0;
}
