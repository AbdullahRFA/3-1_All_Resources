#include <graphics.h>
#include <iostream>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    std::cout << "Enter the coordinates of the starting point (x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter the coordinates of the ending point (x2, y2): ";
    std::cin >> x2 >> y2;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = std::max(abs(dx), abs(dy));
    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(static_cast<int>(x), static_cast<int>(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }

    delay(5000000);
    closegraph();
    return 0;
}

