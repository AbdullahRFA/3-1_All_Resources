#include <graphics.h>
#include <math.h>
#include<bits/stdc++.h>

using namespace std;

void rotatePoint(int x, int y, int& x_rot, int& y_rot, int angle) {
    // Convert angle to radians
    float angle_rad = angle * 3.14159 / 180;

    // Apply rotation transformation
    x_rot = x * cos(angle_rad) - y * sin(angle_rad);
    y_rot = x * sin(angle_rad) + y * cos(angle_rad);
}

void scanConvertLine(int x1, int y1, int x2, int y2, int angle) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Rotate the line
    int x1_rot, y1_rot, x2_rot, y2_rot;
    rotatePoint(x1, y1, x1_rot, y1_rot, angle);
    rotatePoint(x2, y2, x2_rot, y2_rot, angle);

    // Calculate the rotated slope
    float m_rot = static_cast<float>(y2_rot - y1_rot) / (x2_rot - x1_rot);

    // Iterate over x-coordinates
    for (int x = x1_rot; x <= x2_rot; ++x) {
        // Calculate y-coordinate using the rotated slope
        int y = static_cast<int>(m_rot * (x - x1_rot) + y1_rot);

        // Plot the pixel
        putpixel(x, y, WHITE);
    }

    delay(500);
    getch();
    closegraph();
}

int main() {
    // Original line coordinates
    int x1,x2,y1,y2;
    cout<<"Enter the co-ordinates: ";
    cin>>x1>>x2>>y1>>y2;
   // int x1 = 0;
   // int y1 = 0;
    //int x2 = 100;
    //int y2 = 50;

    // Rotation angle in degrees
    int rotation_angle = 30;

    // Scan convert the rotated line
    scanConvertLine(x1, y1, x2, y2, rotation_angle);

    return 0;
}
