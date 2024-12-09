#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");
    setbkcolor(WHITE);
    int x,y,r,x0,y0,d;
    cout << "Enter the coordinates of the center: ";
    cin >>x0>>y0 ;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    x=r;
    y=0;
    d=1-r;
    while (y <= x)
    {
        putpixel(x + x0, y + y0, WHITE);
        putpixel(-x + x0, y + y0, WHITE);
        putpixel(x + x0, -y + y0, WHITE);
        putpixel(-x + x0, -y + y0, WHITE);
        putpixel(y + x0, x + y0, WHITE);
        putpixel(-y + x0, x + y0, WHITE);
        putpixel(y + x0, -x + y0, WHITE);
        putpixel(-y + x0, -x + y0, WHITE);
        y++;
        if (d <= 0)
        {
            d += 2 * y + 1;
        }
        else
        {
            x--;
            d += 2 * (y - x) + 1;
        }
    }
    getch();
    closegraph();
    return 0;
}
