#include <iostream>

int main()
{
    // Define the coordinates of the point
    int x = 3;
    int y = 2;

    // Define the size of the pixel buffer
    int width = 10;
    int height = 5;

    // Create a 2D pixel buffer initialized with empty spaces
    char pixelBuffer[5][10];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pixelBuffer[i][j] = ' ';
        }
    }

    // Scan convert the point
    if (x >= 0 && x < width && y >= 0 && y < height) {
        pixelBuffer[y][x] = '*';
    }

    // Print the pixel buffer
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << pixelBuffer[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
