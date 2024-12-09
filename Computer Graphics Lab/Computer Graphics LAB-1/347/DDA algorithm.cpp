#include<iostream>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
using namespace std;
int main()
{
int x0,y0,x1,y1,i,x,y;
cout<<"Enter first coordinate"<<endl;
cin>>x0>>y0;
cout<<"Enter the second coordinate"<<endl;
cin>>x1>>y1;
int dx=(x1-x0);
int dy=(y1-y0);
int steps;
int gr=DETECT,gm;
initgraph(&gr,&gm,"C:\\TURBOC3\\BGI");
if(dx>=dy)
{
 steps=dx;
}
else
{
steps=dy;
}
dx=dx/steps;
dy=dy/steps;
x=x0;
y=y0;
for(i=1;i<=steps;i++)
{
   putpixel(x,y,RED);
   x+=dx;
   y+=dy;
}
  getch();
 closegraph();
return 0;
}
