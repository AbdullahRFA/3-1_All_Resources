#include <graphics.h>
#include<bits/stdc++.h>
using namespace std;
void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));

    float xIncrement = (float)(dx) / steps;
    float yIncrement = (float)(dy) / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; ++i) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;

    printf("Enter the starting point (x1, y1): ");
    scanf("%d%d", &x1, &y1);

    printf("Enter the ending point (x2, y2): ");
    scanf("%d%d", &x2, &y2);

    drawLineDDA(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}
