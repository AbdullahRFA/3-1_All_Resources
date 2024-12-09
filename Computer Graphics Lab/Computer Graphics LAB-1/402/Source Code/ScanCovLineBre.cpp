#include <graphics.h>
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    while (true) {
        putpixel(x1, y1, WHITE);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    int x1, x2, y1, y2;
	printf("Enter X1, X2 = ");
    scanf("%d%d",&x1, &x2);
    printf("Enter Y1, Y2 = ");
    scanf("%d%d",&y1, &y2);
    drawLine(x1, y1, x2, y2); // Draw the line from (x1, y1) to (x2, y2)
    delay(5000); // Delay to show the output
    closegraph();
    return 0;
}
