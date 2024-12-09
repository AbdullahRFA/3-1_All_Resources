#include <iostream>
#include <cmath>
using namespace std;

void scanConvertCircleBresenham(int centerX, int centerY, int radius)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;
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
    while (x <= y)
    {
        if (centerX + x >= 0 && centerX + x < width && centerY + y >= 0 && centerY + y < height)
            grid[centerY + y][centerX + x] = '*';
        if (centerX - x >= 0 && centerX - x < width && centerY + y >= 0 && centerY + y < height)
            grid[centerY + y][centerX - x] = '*';
        if (centerX + x >= 0 && centerX + x < width && centerY - y >= 0 && centerY - y < height)
            grid[centerY - y][centerX + x] = '*';
        if (centerX - x >= 0 && centerX - x < width && centerY - y >= 0 && centerY - y < height)
            grid[centerY - y][centerX - x] = '*';
        if (centerY + x >= 0 && centerY + x < height && centerX + y >= 0 && centerX + y < width)
            grid[centerY + x][centerX + y] = '*';
        if (centerY - x >= 0 && centerY - x < height && centerX + y >= 0 && centerX + y < width)
            grid[centerY - x][centerX + y] = '*';
        if (centerY + x >= 0 && centerY + x < height && centerX - y >= 0 && centerX - y < width)
            grid[centerY + x][centerX - y] = '*';
        if (centerY - x >= 0 && centerY - x < height && centerX - y >= 0 && centerX - y < width)
            grid[centerY - x][centerX - y] = '*';
        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
          cout << grid[i][j];
        }
        cout <<endl;
    }
}

int main()
{
    int centerX = 40;
    int centerY = 12;
    int radius = 10;

    scanConvertCircleBresenham(centerX, centerY, radius);
    return 0;

}
