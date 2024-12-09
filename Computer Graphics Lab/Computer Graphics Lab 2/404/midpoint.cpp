#include <iostream>
#include <graphics.h>

void setPixel(int* pixels, int x, int y, int color) {
    // Calculate the index of the pixel in the array based on the (x, y) coordinates
    int index = y * getmaxx() + x;

    // Set the color value of the pixel in the array
    pixels[index] = color;
}

void drawCircle(int* pixels, int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x <= y) {
        setPixel(pixels, xc + x, yc + y, WHITE);
        setPixel(pixels, xc + y, yc + x, WHITE);
        setPixel(pixels, xc - x, yc + y, WHITE);
        setPixel(pixels, xc - y, yc + x, WHITE);
        setPixel(pixels, xc + x, yc - y, WHITE);
        setPixel(pixels, xc + y, yc - x, WHITE);
        setPixel(pixels, xc - x, yc - y, WHITE);
        setPixel(pixels, xc - y, yc - x, WHITE);

        x++;

        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
}

int main() {
    int xc, yc, radius;
    std::cout << "Enter center coordinates (xc and yc): ";
    std::cin >> xc >> yc;
    std::cout << "Enter radius: ";
    std::cin >> radius;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Get the maximum X and Y coordinates of the graphics window
    int maxX = getmaxx();
    int maxY = getmaxy();

    // Create an array to store the pixel data
    int* pixels = new int[maxX * maxY];

    // Initialize the pixel array with background color
    for (int i = 0; i < maxX * maxY; i++) {
        pixels[i] = BLACK;
    }

    drawCircle(pixels, xc, yc, radius);

    // Draw the pixel array on the graphics window
    for (int x = 0; x < maxX; x++) {
        for (int y = 0; y < maxY; y++) {
            putpixel(x, y, pixels[y * maxX + x]);
        }
    }

    getch();
    closegraph();
    return 0;
}
