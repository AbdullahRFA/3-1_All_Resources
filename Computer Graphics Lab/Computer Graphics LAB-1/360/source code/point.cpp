#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm, "Hello");
    putpixel(100,100,WHITE);
    getch();
    closegraph();
}

