#include<graphics.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
intgd = DETECT, gm;

initgraph(&gd, &gm, "C:\\TC\\BGI");
float x = 10, y = 20;
putpixel (x, y, RED);
getch();
closegraph();
return 0;
}

