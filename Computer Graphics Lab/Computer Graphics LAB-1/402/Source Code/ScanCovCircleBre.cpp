#include <graphics.h>
void drawCircle(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;
    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (d < 0)
            d += 4 * x + 6;
        else {
            d += 4 * (x - y) + 10;
            y--;
        }

        x++;
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int xc, yc, radius;
    printf("Enter X coordiate of the center: ");
    scanf("%d", &xc);
    printf("Enter Y co-ordinate of the center: ");
    scanf("%d", &yc);
    printf("Enter the circle radius: ");
    scanf("%d", &radius);
    drawCircle(xc, yc, radius); // Draw the circle
    delay(5000); // Delay to show the output
    closegraph();
    return 0;
}
