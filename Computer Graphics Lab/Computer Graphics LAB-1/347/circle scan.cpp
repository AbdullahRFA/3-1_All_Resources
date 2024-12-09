#include <iostream>
#include <dos.h>
#include <graphics.h>
using namespace std;
void drawCircle(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, RED);
	putpixel(xc-x, yc+y, RED);
	putpixel(xc+x, yc-y, RED);
	putpixel(xc-x, yc-y, RED);
	putpixel(xc+y, yc+x, RED);
	putpixel(xc-y, yc+x, RED);
	putpixel(xc+y, yc-x, RED);
	putpixel(xc-y, yc-x, RED);
}
void circlebres(int xc, int yc, int r)
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
	}
}
int main()
{
	int xc ,yc,r;
	int gd = DETECT, gm;
	cout<<"Enter the center point"<<endl;
	cin>>xc>>yc;
	cout<<"Enter the radius"<<endl;
	cin>>r;
	initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");
	circlebres(xc, yc, r);
	getch();
closegraph();
	return 0;
}
