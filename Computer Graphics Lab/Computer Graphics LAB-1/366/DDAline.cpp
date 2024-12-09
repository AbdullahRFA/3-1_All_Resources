#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void scanConvertLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;
    float x = x1;
    float y = y1;
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
    int x1 = 1;
    int y1 = 1;
    int x2 = 8;
    int y2 = 4;
    scanConvertLine(x1, y1, x2, y2);

    return 0;
}

