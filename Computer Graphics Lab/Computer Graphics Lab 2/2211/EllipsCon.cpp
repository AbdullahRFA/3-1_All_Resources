#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void drawellipse(int xc,int yc,int x,int y)
{
    putpixel(xc+x,yc+y,YELLOW);
    putpixel(xc+x,yc-y,YELLOW);
    putpixel(xc-x,yc+y,YELLOW);
    putpixel(xc-x,yc-y,YELLOW);
}
void midpointEllipse(int xc,int yc,int a,int b)
{
  int x=0;
  int y=b;
  double d1=b*b-a*a*b+0.25*a*a;
  int dx=2*b*b*x;
  int dy=2*a*a*y;
  while(dx<dy)
  {
      drawellipse(xc,yc,x,y);
      if(d1<0)
      {
          x++;
          dx=dx+2*b*b;
          d1=d1+dx+b*b;
      }
      else
        {
        x++;
      y--;
      dx=dx+2*b*b;
      dy=dy-2*a*a;

      d1=d1+dx-dy+b*b;
      }
  }
  double d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
  while(y>=0)
        {
            drawellipse(xc,yc,x,y);
            if(d2>0)
                {
                    y--;
                    dy=dy-2*a*a;
                    d2=d2+a*a-dy;
                }
                else
                {

                    y--;
                    x++;
                    dx=dx+2*b*b;
                    dy=dy-2*a*a;
                    d2=d2+dx-dy+a*a;
                }
        }
}
int main()
{
    int xc,yc,a,b;
    cout<<"Enter center coordinates,max axis ,min axis: ";
    cin>>xc>>yc>>a>>b;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    setcolor(YELLOW);
    midpointEllipse(xc,yc,a,b);
    getch();
    closegraph();
    return 0;


}
