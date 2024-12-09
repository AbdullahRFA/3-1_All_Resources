#include <graphics.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Scan Convert a line object from (0, 0) to (100, 50)
    line(0, 0, 100, 50);

    // Rotate the line by 30 degrees
    //printf("Choose the options below: \n");
    //printf("1. ")
    int angle = 30;
    float radian = angle * (M_PI / 180.0);
    int x0 = 0, y0 = 0, x1 = 100, y1 = 50;
    int new_x0 = round(x0 * cos(radian) - y0 * sin(radian));
    int new_y0 = round(x0 * sin(radian) + y0 * cos(radian));
    int new_x1 = round(x1 * cos(radian) - y1 * sin(radian));
    int new_y1 = round(x1 * sin(radian) + y1 * cos(radian));
    line(new_x0, new_y0, new_x1, new_y1);

    // Scale the line to 50%
    float scale = 0.5;
    new_x0 = round(new_x0 * scale);
    new_y0 = round(new_y0 * scale);
    new_x1 = round(new_x1 * scale);
    new_y1 = round(new_y1 * scale);
    line(new_x0, new_y0, new_x1, new_y1);

    // Translate the line on the x-axis by 75 pixels
    int translation_x = 75;
    new_x0 += translation_x;
    new_x1 += translation_x;
    line(new_x0, new_y0, new_x1, new_y1);

    getch();
    closegraph();
    return 0;
}
