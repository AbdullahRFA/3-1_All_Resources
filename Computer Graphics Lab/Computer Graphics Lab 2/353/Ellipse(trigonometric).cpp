#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
void drawEllipse(int xc, int yc, int rx, int ry)
{
    int numPoints = 360;
    double angleIncrement = (2*3.1416)/numPoints;
    for (int i = 0; i < numPoints; ++i)
    {
        double angle = i * angleIncrement;
        int x = xc + round(rx * cos(angle));
        int y = yc + round(ry * sin(angle));
        putpixel(x, y, WHITE);
    }
}
int main()
{
    int xc, yc, rx, ry;
    cout << "Enter the center coordinates (xc, yc): ";
    cin>>xc>>yc;
    cout<<"Enter the major radius (rx): ";
    cin>>rx;
    cout<<"Enter the minor radius (ry): ";
    cin>>ry;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawEllipse(xc, yc, rx, ry);
    delay(5000);
    getch();
    closegraph();
    return 0;
}
