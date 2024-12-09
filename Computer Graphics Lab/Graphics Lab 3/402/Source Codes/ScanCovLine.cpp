#include <graphics.h>
#include <math.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    // Scan Convert a line object from (0, 0) to (100, 50)
    line(0, 0, 100, 50);
    getch();
    closegraph();
    return 0;
}
