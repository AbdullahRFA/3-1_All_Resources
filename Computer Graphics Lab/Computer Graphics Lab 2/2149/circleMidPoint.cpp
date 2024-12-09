#include <iostream>
#include<bits/stdc++.h>
#include <graphics.h>

using namespace std;

void drawCircle(int radius, int xc, int yc) {
    int x = 0;              // Initial x coordinate
    int y = radius;         // Initial y coordinate
    int d = 1 - radius;     // Initial decision parameter

    // Initialize the graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Plot the first point in all eight octants
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);

    // Loop until x is greater than or equal to y
    while (x <= y) {
        if (d < 0) {
            // Move to the right and update the decision parameter
            x++;
            d += 2 * x + 1;
        }
        else {
            // Move to the upper right and update the decision parameter
            x++;
            y--;
            d += 2 * (x - y) + 1;
        }

        // Plot the points in all eight octants
        putpixel(xc + x, yc + y, YELLOW);
        putpixel(xc - x, yc + y, YELLOW);
        putpixel(xc + x, yc - y, YELLOW);
        putpixel(xc - x, yc - y, YELLOW);
        putpixel(xc + y, yc + x, YELLOW);
        putpixel(xc - y, yc + x, YELLOW);
        putpixel(xc + y, yc - x, YELLOW);
        putpixel(xc - y, yc - x, YELLOW);
    }

    // Delay to show the graphics window
    delay(588000);

    // Close the graphics window
    closegraph();
}

int main() {
    int radius; //100
    int xc;   // X-coordinate of the center 320
    int yc;   // Y-coordinate of the center 240

    cout<<"Enter the x axis and y axis:"<<endl;
    cin>>xc;
    cin>>yc;
    cout<<"Enter the radius of the circle: "<<endl;
    cin>>radius;
    drawCircle(radius, xc, yc);

    return 0;
}

