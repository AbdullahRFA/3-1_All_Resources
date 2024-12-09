#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void scanConvertLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int dx2 = dx * 2;
    int dy2 = dy * 2;
    int ix = (x1 < x2) ? 1 : -1;
    int iy = (y1 < y2) ? 1 : -1;
    int x = x1;
    int y = y1;
    if (dx > dy) {
        int error = dy2 - dx;
        while (x != x2) {
            std::cout << "(" << x << ", " << y << ")" << std::endl;
            if (error >= 0) {
                y += iy;
                error -= dx2;
            }
            error += dy2;
            x += ix;
        }
    } else {
        int error = dx2 - dy;
        while (y != y2) {
            std::cout << "(" << x << ", " << y << ")" << std::endl;
            if (error >= 0) {
                x += ix;
                error -= dy2;
            }
            error += dx2;
            y += iy;
        }
    }
    cout << "(" << x2 << ", " << y2 << ")" << endl;
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

