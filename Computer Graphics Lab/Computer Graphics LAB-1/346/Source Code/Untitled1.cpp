#include<bits/stdc++.h>#include<graphics.h>
#include<dos.h>
#include<math.h>
using namespace std;
 void main()
 {
     int gd=DETECT,gm;
     int x1,y1,x2,y2,dx,dy,steps,xinc,yinc;
     initgraph(&gd,&gm,"");
     cout<<"Enter starting coordinates: ";
     cin>>x1>>y1;
     cout<<"Enter ending coordinates: ";
     cin>>x2>>y2;
     dx= x2-x1;
     dy= y2-y1;
     if(abs(dx)>abs(dy))
        steps=(dx);
     else
        steps=(dy);
        xincr=dx/steps;
        yincr=dy/steps;
        for(i=0;i<steps;i++)
        {
            putpixel(x1,y1,3);
            x1=x1+xincr;
            y1=y1+yincr;
        }
        getch();
        closegraph();

 }
