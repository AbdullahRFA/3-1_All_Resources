#include<bits/stdc++.h>
#include<graphics.h>
 using namespace std;
void drawlinedda(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xincrement = static_cast<float>(dx) / steps;
    float yincrement = static_cast<float>(dy) / steps;
    float x = x1;
    float y = y1;

    for(int i=0; i<=steps; i++)
    {
        putpixel(static_cast<int>(x),static_cast<int>(y),WHITE);
        x += xincrement;
        y += yincrement;
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
    drawlinedda(x1,y1,x2,y2);
    delay(50000000);
    closegraph();
    return 0;
}
