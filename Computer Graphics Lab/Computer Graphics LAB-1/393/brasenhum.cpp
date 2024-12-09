#include <iostream>
#include <cmath>
using namespace std;
void scanConvertLineBresenham(int x1, int y1, int x2, int y2)
{

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    const int width = 80;
    const int height = 24;
    char grid[height][width];

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            grid[i][j] = ' ';
        }
    }
    int x = x1;
    int y = y1;

    while (x != x2 || y != y2)
    {
        if (x >= 0 && x < width && y >= 0 && y < height)
        {
            grid[y][x] = '*';
        }
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {

            cout << grid[i][j];
        }
            cout << endl;
    }
}

int main()
{

    cout<<"Scan converting a line using Bresenham algorithm";

    int x1 = 10;
    int y1 = 5;
    int x2 = 70;
    int y2 = 18;
    scanConvertLineBresenham(x1, y1, x2, y2);

    return 0;

}

