#include <fstream>
#include <vector>
#include <stdexcept>
#include "Matrix.hpp"


Matrix loadImageToMatrix(const std::string& filepath) {
    std::ifstream file(filepath, std::ios::binary);

    if (!file) {
        throw std::runtime_error("Cannot open BMP file");
    }

    // BMP Header is 54 bytes
    char header[54];
    file.read(header, 54);

    // Extract width and height from header (positions 18 and 22)
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    if (width != 28 || height != 28) {
        throw std::runtime_error("Image is not 28x28 pixels");
    }

    Matrix matrix(28, 28);
    char pixel[3];  // Each pixel is 3 bytes (BGR format)

    for (int y = 0; y < 28; ++y) {
        for (int x = 0; x < 28; ++x) {
            file.read(pixel, 3);

            // Convert BGR to grayscale
            double gray = 0.3 * pixel[2] + 0.59 * pixel[1] + 0.11 * pixel[0];
            matrix(x, y) = gray / 255.0;  // Normalize to [0, 1]
        }
    }

    file.close();
    return matrix;
}

Matrix loadLabel(const std::string& filepath) {
    std::ifstream file(filepath);

    if (!file) {
        throw std::runtime_error("Cannot open label file");
    }

    std::string line;
    std::getline(file, line);
    file.close();

    Matrix label(2, 1);  // [cat_score, dog_score]
    if (line == "0") {
        label(0, 0) = 1.0;
        label(1, 0) = 0.0;
    } else if (line == "1") {
        label(0, 0) = 0.0;
        label(1, 0) = 1.0;
    } else {
        throw std::runtime_error("Invalid label value");
    }

    return label;
}
