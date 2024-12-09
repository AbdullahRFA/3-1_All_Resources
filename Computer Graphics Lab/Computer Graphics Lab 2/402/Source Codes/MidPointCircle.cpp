#include <graphics.h>
#include <iostream>
using namespace std;
void mid_circle(double x1, double y1, double r) {
    int x = 0;
    int y = r;
    int p = 1-r;
    while(y > x) {
        putpixel(x1 + x, y1 + y, YELLOW);
        putpixel(x1 + y, y1 + x,YELLOW);
        putpixel(x1 - x, y1 + y,RED);
        putpixel(x1 - y, y1 + x, RED);
        putpixel(x1 - x, y1 - y, GREEN);
        putpixel(x1 - y, y1 - x, GREEN);
        putpixel(x1 + x, y1 - y, WHITE);
        putpixel(x1 + y, y1 - x, WHITE);
        if (p < 0) {
            p += 2*x + 1;
        }
        else {
            p += 2*x -2*y+1;
            y=y-1;
        }
        x=x+1;
        delay(1000);
    }
}
int main(){
    double x1, y1, r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    cout<<"Enter the starting co - ordinates of a center (x, y): ";
    cin>>x1>>y1;
    cout<<"Enter the value of radius: ";
    cin>>r;
    mid_circle(x1, y1, r);
    getch();
    closegraph();
    return 0;
}

