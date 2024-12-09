#include<bits/stdc++.h>
#include <graphics.h>
#include <math.h>
using namespace std;
void rotatePoint(int x, int y, int& x_rot, int& y_rot, int angle)
{
    float angle_rad = angle * 3.14159 / 180;
    x_rot=x*cos(angle_rad)-y*sin(angle_rad);
    y_rot=x*sin(angle_rad)+y*cos(angle_rad);
}
void scanConvertLine(int x1, int y1, int x2, int y2, int angle)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x1_rot, y1_rot, x2_rot, y2_rot;
    rotatePoint(x1, y1, x1_rot, y1_rot, angle);
    rotatePoint(x2, y2, x2_rot, y2_rot, angle);
    float m_rot = static_cast<float>(y2_rot - y1_rot)/(x2_rot - x1_rot);
    for (int x = x1_rot; x <= x2_rot; ++x) {
        int y = static_cast<int>(m_rot*(x-x1_rot)+y1_rot);
        putpixel(x, y, WHITE);
    }
    delay(500);
    getch();
    closegraph();
}
int main() {
    int x1 = 0;
    int y1 = 0;
    int x2 = 100;
    int y2 = 50;
    int rotation_angle = 30;
    scanConvertLine(x1, y1, x2, y2, rotation_angle);
    return 0;
}
