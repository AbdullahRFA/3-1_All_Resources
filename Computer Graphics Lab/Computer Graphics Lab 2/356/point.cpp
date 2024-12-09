#include<bits/stdc++.h>
#include <graphics.h>
#include <conio.h>
using namespace std;

int main()
{

    int x, y;
    cout << "\nEnter the x-coordinate: ";
    cin >> x;
    cout << "\nEnter the y-coordinate: ";
    cin >> y;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    putpixel(x, y, WHITE);

    getch();
    closegraph();

    return 0;
}
