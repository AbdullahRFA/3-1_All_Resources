#include <graphics.h>
#include <iostream>
using namespace std;

void bresenham(int x1, int y1, int x2, int y2)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int m_new = 2 * (y2 - y1);
    int slope_error_new = m_new - (x2 - x1);

    for (int x = x1, y = y1; x <= x2; x++) {
        putpixel(x, y, WHITE);
        delay(10);
        slope_error_new += m_new;

        if (slope_error_new >= 0) {
            y++;
            slope_error_new -= 2 * (x2 - x1);
        }
    }

    getch();
    closegraph();
}

int main()
{
    int x1, y1, x2, y2;

    cout << "\nEnter the starting x-coordinate: ";
    cin >> x1;

    cout << "Enter the starting y-coordinate: ";
    cin >> y1;

    cout << "\nEnter the ending x-coordinate: ";
    cin >> x2;

    cout << "Enter the ending y-coordinate: ";
    cin >> y2;

    bresenham(x1, y1, x2, y2);
    return 0;
}

