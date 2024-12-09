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
void circlemid(int xc, int yc, int r)
{
	int x = 0, y = r;
	int p=(1-r);
	drawCircle(xc, yc, x, y);
	while (y >= x)
	{
		x++;

		if (p> 0)
		{
			y--;
			p+=2*(x-y)+1;
		}
		else
		{
			p+=2*x+1;
        }
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
	circlemid(xc, yc, r);
	getch();
    closegraph();
	return 0;
}
