#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");
    setbkcolor(WHITE);
    float x_f,y_f;
    int w,h,i,j;
    cout<<"Enter co-ordinates the point for scan conversion: ";
    cin>>x_f>>y_f;
    int x,y;
    x=round(x_f);
    y=round(y_f);
    putpixel(x, y, GREEN);
    getch();
    closegraph();
    return 0;
}
