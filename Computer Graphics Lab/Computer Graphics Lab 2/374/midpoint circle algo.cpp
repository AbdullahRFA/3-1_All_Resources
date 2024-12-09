#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void midpoint_circle(int cx, int cy, int r)
{
    int x,y,decision;
    x=0,y=r,decision=1-r;
    while (x <= y)
    {
        putpixel(cx + x, cy + y, WHITE);
        putpixel(cx - x, cy + y, WHITE);
        putpixel(cx + x, cy - y, WHITE);
        putpixel(cx - x, cy - y, WHITE);
        putpixel(cx + y, cy + x, WHITE);
        putpixel(cx - y, cy + x, WHITE);
        putpixel(cx + y, cy - x, WHITE);
        putpixel(cx - y, cy - x, WHITE);

        if (decision < 0) decision += (2*x+3);
        else
        {
            decision += (2 * (x - y) + 5);
            y--;
        }
        x++;
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int cx,cy,r;
    cout<<"Midpoint Circle Algorithm"<<endl;
    cout << "Enter center coordinates (x, y) and radius of the circle: ";
    cin >> cx >> cy >>r;

    midpoint_circle(cx, cy, r);
    getch();
    closegraph();
    return 0;
}
