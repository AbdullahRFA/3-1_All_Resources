#include <iostream>
#include <graphics.h>
using namespace std;

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;

    float x = static_cast<float>(x1);
    float y = static_cast<float>(y1);

    for (int i = 0; i <= steps; ++i) {
        putpixel(static_cast<int>(x), static_cast<int>(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int x1 = 100, y1 = 100;
    int x2 = 400, y2 = 300;
    cout<<"Enter X1 value and Y1 vale : ";
    cin>>x1>>y1;
    cout<<"Enter X2 value Y2 value : ";
    cin>>x2>>y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawLineDDA(x1, y1, x2, y2);

    delay(200000);
    closegraph();

    return 0;
}

