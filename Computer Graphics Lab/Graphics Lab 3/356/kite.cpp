#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main()

{
int gd,gm;
detectgraph(&gd,&gm);

initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
line(200,200,300,100);
line(300,100,400,200);
line(400,200,300,300);
line(300,100,300,300);
line(300,300,200,200);
arc(300,300,45,135,140);
setfillstyle(SOLID_FILL,GREEN);

floodfill(301,105,WHITE);
setfillstyle(SOLID_FILL,LIGHTGRAY);

floodfill(299,105,WHITE);
setfillstyle(SOLID_FILL,LIGHTCYAN);


floodfill(299,275,WHITE);
setfillstyle(SOLID_FILL,LIGHTBLUE);


floodfill(301,275,WHITE);
line(300,300,250,350);
line(250,350,350,350);
line(300,300,350,350);
setfillstyle(SOLID_FILL,CYAN);


floodfill(300,310,WHITE);
getch();
closegraph();
}
