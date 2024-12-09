#include <iostream>
using namespace std;
void drawCircle(int radius)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;

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
}

int main()
{
    int radius;
    cout << "Enter the radius of the circle: ";
   cin >> radius;

    cout << "Coordinates of the circle using Bresenham's Circle Algorithm:" <<endl;
    drawCircle(radius);

    return 0;
}
