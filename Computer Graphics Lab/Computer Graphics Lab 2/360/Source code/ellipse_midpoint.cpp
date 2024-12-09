#include <iostream>
#include <graphics.h>
#include<math.h>

void drawEllipse(int a, int b, int xc, int yc) {
    int x = 0;
    int y = b;

    int a_squared = a * a;
    int b_squared = b * b;
    int two_a_squared = 2 * a_squared;
    int two_b_squared = 2 * b_squared;
    int four_a_squared = 4 * a_squared;
    int four_b_squared = 4 * b_squared;
    int x_end = b_squared / sqrt(a_squared + b_squared);
    int dx = 0;
    int dy = two_a_squared * y;


    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc + x, yc + y, WHITE);


    int p1 = round(b_squared - (a_squared * b) + (0.25 * a_squared));

    while (dx < dy) {
        x++;

        if (p1 < 0) {
            dx += two_b_squared;
            p1 += dx + b_squared;
        } else {
            y--;
            dx += two_b_squared;
            dy -= two_a_squared;
            p1 += dx - dy + b_squared;
        }


        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
    }

    int p2 = round(b_squared * (x + 0.5) * (x + 0.5) + a_squared * (y - 1) * (y - 1) - a_squared * b_squared);

    while (y > 0) {
        y--;

        if (p2 > 0) {
            dy -= two_a_squared;
            p2 += a_squared - dy;
        } else {
            x++;
            dx += two_b_squared;
            dy -= two_a_squared;
            p2 += dx - dy + a_squared;
        }

        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
    }

    delay(5000);


    closegraph();
}

int main() {
    int a = 200;
    int b = 100;
    int xc = 250;
    int yc = 250;

    drawEllipse(a, b, xc, yc);

    return 0;
}
