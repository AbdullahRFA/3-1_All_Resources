#include <iostream>
#include <graphics.h>
using namespace std;

int main() {
    int x,y,redius;
    cout<<"Enter X1 value and Y1 vale : ";
    cin>>x>>y;
    cout<<"Enter value of R : ";
    cin>>redius;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    circle(x, y, redius);

    delay(200000);
    closegraph();

    return 0;
}

