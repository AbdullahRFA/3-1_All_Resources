#include <iostream>
#include<graphics.h>
using namespace std;
void scanConvertPoint(int x, int y)
{

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
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        grid[y][x] = '*';

    }
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            cout<<grid[i][j];
        }
        cout << endl;
    }
}
int main()
{

    int pointX = 40;
    int pointY = 12;

    scanConvertPoint(pointX, pointY);
    return 0;

}

