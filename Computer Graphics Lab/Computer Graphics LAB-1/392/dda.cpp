#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function to perform scan conversion of a line using DDA algorithm
void scanConvertLine(int x1, int y1, int x2, int y2)
{
    // Calculate the number of steps
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate the increment values for each step
    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;

    // Initialize the current position
    float x = x1;
    float y = y1;

    // Perform scan conversion and print the resulting points
    for (int i = 0; i <= steps; i++) {
        int roundedX = static_cast<int>(round(x));
        int roundedY = static_cast<int>(round(y));
        cout << "(" << roundedX << ", " << roundedY << ")" << endl;
        x += xIncrement;
        y += yIncrement;
    }
}

int main()
{
    // Example line coordinates
    int x1 = 0;
    int y1 = 0;
    int x2 = 7;
    int y2 = 9;

    // Perform scan conversion of the line
    scanConvertLine(x1, y1, x2, y2);

    return 0;
}

