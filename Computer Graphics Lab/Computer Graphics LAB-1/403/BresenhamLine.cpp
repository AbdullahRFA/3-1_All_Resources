#include<bits/stdc++.h>
#include<graphics.h>
 using namespace std;
void drawlinebresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2- y1);
    int sx = (x1 < x2)? 1 : -1;
    int sy = (y1 < y2)? 1 : -1;
    int err = dx - dy;
    while(true)
    {
        putpixel(x1,y1,WHITE);
        if(x1==x2 && y1==y2)
            break;
        int dt = 2*err;
        if(dt>-dy)
        {
            err -= dy;
            x1 += sx;
        }
        if(dt < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm, "");

    int x1,y1,x2,y2;

    cout << "Enter first coordinate (x1,y1):" << endl;
    cin >> x1 >> y1;
    cout << "Enter first coordinate (x2,y2):" << endl;
    cin >> x2>>y2;
    drawlinebresenham(x1,y1,x2,y2);
    delay(50000000);
    closegraph();
    return 0;
}
