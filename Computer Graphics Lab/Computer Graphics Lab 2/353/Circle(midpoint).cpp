#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
void drawCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 1 - r;

    while (x <= y) {
        putpixel(xc + x, yc + y, BLUE);
        putpixel(xc - x, yc + y, BLUE);
        putpixel(xc + x, yc - y, BLUE);
        putpixel(xc - x, yc - y, BLUE);
        putpixel(xc + y, yc + x, BLUE);
        putpixel(xc - y, yc + x, BLUE);
        putpixel(xc + y, yc - x, BLUE);
        putpixel(xc - y, yc - x, BLUE);

        if (d >= 0) {
            y--;
            d += 2 * (x - y) + 1;
        } else {
            d += 2 * x + 1;
        }
        x++;
    }
}
int main()
{
    int x,y,r;
    cout<<"Enter the center coordinates (x, y): ";
    cin>>x>>y;
    cout<<"Enter the radius (r): ";
    cin>>r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawCircle(x,y,r);
    delay(5000);
    getch();
    closegraph();
    return 0;
}
