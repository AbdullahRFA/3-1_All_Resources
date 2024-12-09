
#include <dos.h>
#include<bits/stdc++.h>
#include <graphics.h>
#include <conio.h>
using namespace std;

void drawCircle(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, GREEN);
	putpixel(xc-x, yc+y, GREEN);
	putpixel(xc+x, yc-y, GREEN);
	putpixel(xc-x, yc-y, GREEN);
	putpixel(xc+y, yc+x, GREEN);
	putpixel(xc-y, yc+x, GREEN);
	putpixel(xc+y, yc-x, GREEN);
	putpixel(xc-y, yc-x, GREEN);
}


void circleBres(int xc, int yc, int r)
{
	int x = 0, y = r;
	int d = 3 - 2 * r;
	drawCircle(xc, yc, x, y);
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawCircle(xc, yc, x, y);
		delay(50);
	}
	getch();
    closegraph();
}

int main()
{
	int x, y, r;

    cout << "\nEnter the x-coordinate of the center: ";
    cin >> x;

    cout << "Enter the y-coordinate of the center: ";
    cin >> y;

    cout << "\nEnter the Radius of the circle: ";
    cin >> r;

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	circleBres(x, y, r);
	return 0;
}

