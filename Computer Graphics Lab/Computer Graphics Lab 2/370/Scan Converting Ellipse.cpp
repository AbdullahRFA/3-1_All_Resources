#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
void EllipseScanConversion(int xc, int yc, int a, int b) {
    int x = 0;
    int y = b;

    int decision = (b*b) - (a*a) * b + (a*a) / 4;

    while ((2*b*b) * x < (2*a*a) * y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (decision <= 0) {
            x++;
            decision += (2*b*b) * x + (b*b);
        } else {
            x++;
            y--;
            decision += (2*b*b) * x - (2*a*a) * y + (b*b);
        }
    }

    decision = (b*b) * (x + 0.5) * (x + 0.5) + (a*a) * (y - 1) * (y - 1) - (a*a) * (b*b);

    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (decision > 0) {
            y--;
            decision += (a*a) - (2*a*a) * y;
        } else {
            y--;
            x++;
            decision += (2*b*b) * x - (2*a*a) * y + (a*a);
        }
    }
}

int main() {
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
    errorcode = graphresult();

    if (errorcode != grOk)
    {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1);
    }


    int xc, yc, a, b;
    cout << "Enter center coordinates (x, y): ";
    cin >> xc >> yc;
    cout << "Enter semi-major axis (a): ";
    cin >> a;
    cout << "Enter semi-minor axis (b): ";
    cin >> b;

    EllipseScanConversion(xc, yc, a, b);

    getch();
    closegraph();
    return 0;
}
