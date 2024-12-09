#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm, "second");
    putpixel(222,222,WHITE);
    getch();
    closegraph();
}
