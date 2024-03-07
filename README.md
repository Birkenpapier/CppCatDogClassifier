# CppCatDogClassifier
An end-to-end C++ implementation of a neural network built from scratch for detecting and classifying images of dogs and cats.

> [!WARNING]
> This software is unfinished. Keep your expectations low.

## Table of Contents

- [CppCatDogClassifier](#cppcatdogclassifier)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Project Structure](#project-structure)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Compiling and Running](#compiling-and-running)
  - [Implementation Details](#implementation-details)
  - [Future Enhancements](#future-enhancements)
  - [License](#license)
  - [Acknowledgements](#acknowledgements)

## Introduction

This project aims to provide a basic understanding of neural networks by creating a feed-forward neural network in C++ without relying on third-party libraries. The neural network is trained using a dataset of 28x28 grayscale images to detect if an image contains a dog or a cat.

## Project Structure

```
NeuralNetworkProject:
|-- data:
|   |-- images:
|   |   |-- cat1.bmp
|   |   |-- cat2.bmp
|   |   ...
|   |-- labels:
|   |   |-- cat1.txt
|   |   |-- cat2.txt
|   |   ...
|-- src:
|   |-- ActivationFunction.cpp
|   |-- LoadImages.cpp
|   |-- main.cpp
|   |-- Matrix.cpp
|   |-- NeuralNetwork.cpp
|-- include:
|   |-- ActivationFunction.hpp
|   |-- Matrix.hpp
|   |-- NeuralNetwork.hpp
```

## Getting Started

### Prerequisites

1. Ensure you have a C++ compiler installed, preferably GCC.
2. Prepare your dataset:
    - Place BMP images (28x28 pixels and 24-bit format) in the `data/images` directory.
    - Place corresponding labels in the `data/labels` directory.

### Compiling and Running

1. Navigate to the `NeuralNetworkProject` directory.
2. Compile the project using the following command:
\```bash
g++ -o NeuralNetwork -Iinclude src/*.cpp -std=c++11
\```
3. Execute the compiled program:
\```bash
./NeuralNetwork
\```

## Implementation Details

- `Matrix`: Handles matrix operations vital for the neural network.
- `ActivationFunction`: Defines the sigmoid activation function and its derivative for neuron activations.
- `NeuralNetwork`: Establishes the neural network's structure and operations, including feed-forward and backpropagation.
- `LoadImages`: Contains functions to load BMP images and their corresponding labels.

## Future Enhancements

- Improve neural network architecture with convolutional layers.
- Implement mini-batch gradient descent.
- Split the dataset into training, validation, and test sets.
- Utilize a build system like `make` or `CMake` for efficient compilation.

## License

This project is open-source and available under the [MIT License](LICENSE.md).

## Acknowledgements

- The [Kaggle Dogs vs. Cats](https://www.kaggle.com/c/dogs-vs-cats/data) dataset for initial training data inspiration.
