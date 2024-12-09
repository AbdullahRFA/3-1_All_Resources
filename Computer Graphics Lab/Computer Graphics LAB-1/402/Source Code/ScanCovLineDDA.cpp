#include <graphics.h>
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(static_cast<int>(x), static_cast<int>(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
	float x1, x2, y1, y2;
	printf("Enter X1, X2 = ");
    scanf("%f%f",&x1, &x2);
    printf("Enter Y1, Y2 = ");
    scanf("%f%f",&y1, &y2);
    drawLine(x1, y1, x2, y2); // Draw the line from (x1, y1) to (x2, y2)
    delay(5000); // Delay to show the output
    closegraph();
    return 0;
}
