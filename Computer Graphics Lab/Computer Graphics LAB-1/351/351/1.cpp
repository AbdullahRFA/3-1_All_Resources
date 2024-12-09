#include <graphics.h>
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    int a, b;
    cout << "Enter the x-coordinate: ";
    cin >> a;
    cout << "Enter the y-coordinate: ";
    cin >> b;
    initgraph(&gd, &gm, "");
    putpixel(a, b, WHITE);
    getch();
    closegraph();
    return 0;
}
