#include <iostream>
#include <cmath>
using namespace std;
void scanConvertLineDDA(int x1, int y1, int x2, int y2)

{

    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ?abs(dx) : abs(dy);
    float xIncrement =float(dx) / steps;
    float yIncrement = float(dy) / steps;

    float x = float(x1);
    float y = float(y1);

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

    for (int i = 0; i <= steps; ++i)
    {
        int gridX =int(round(x));
        int gridY = int(round(y));
        if (gridX >= 0 && gridX < width && gridY >= 0 && gridY < height)

        {
            grid[gridY][gridX] = '*';
        }
        x += xIncrement;
        y += yIncrement;

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

    cout<<"Scan converting a line using DDA algorithm";
    int x1 = 10;
    int y1 = 5;
    int x2 = 70;
    int y2 = 18;
    scanConvertLineDDA(x1, y1, x2, y2);

    return 0;

}
