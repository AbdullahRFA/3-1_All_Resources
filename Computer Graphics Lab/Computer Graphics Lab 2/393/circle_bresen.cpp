#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

voidEightWaySymmetricPlot(intxc,intyc,intx,int y)
{
putpixel(x+xc,y+yc,RED);
putpixel(x+xc,-y+yc,RED);
putpixel(-x+xc,-y+yc,RED);
putpixel(-x+xc,y+yc,RED);
putpixel(y+xc,x+yc,RED);
putpixel(y+xc,-x+yc,RED);
putpixel(-y+xc,-x+yc,RED);
putpixel(-y+xc,x+yc,RED);
}

voidBresenhamCircle(intxc,intyc,int r)
{
int x=0,y=r,d=3-(2*r);
EightWaySymmetricPlot(xc,yc,x,y);

while(x<=y)
    {
if(d<=0)
        {
            d=d+(4*x)+6;
        }
else
        {
            d=d+(4*x)-(4*y)+10;
            y=y-1;
        }
        x=x+1;
EightWaySymmetricPlot(xc,yc,x,y);
    }
}

int  main(void)
{

intxc,yc,r,gdriver = DETECT, gmode, errorcode;

initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
errorcode = graphresult();

if (errorcode != grOk)
    {
printf("Graphics error: %s\n", grapherrormsg(errorcode));
printf("Press any key to halt:");
getch();
exit(1);
    }
printf("Enter the values of xc and yc : ");
scanf("%d%d",&xc,&yc);
printf("Enter the value of radius: ");
scanf("%d",&r);
BresenhamCircle(xc,yc,r);

getch();
closegraph();
return 0;
}

