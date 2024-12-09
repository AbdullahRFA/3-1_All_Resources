#include<iostream>
#include<graphics.h>
#include<math.h>
#define pi acos(-1)
using namespace std;

void drawl(int x0,int y0,int x1, int y1){
int dx=abs(x1-x0),dy=abs(y1-y0);
int sx=(x0<x1)?1:-1;
int sy=(y0<y1)?1:-1;
int err=dx-dy;

while(1){
    putpixel(x0,y0,WHITE);
    if(x0==x1&&y0==y1)break;

    int e2=2*err;
    if(e2>-dy){
        err-=dy;
        x0+=sx;
    }
    if(e2<dx){
        err+=dx;
        y0+=sy;
    }
}
}
int main(){
int gd=DETECT,gm;
initgraph(&gd, &gm,"");
int x0=0,y0=0,x1=100,y1=50;
drawl(x0,y0,x1,y1);
x0=0,y0=0;
float angle=pi/6.0;
float cs=cos(angle), sn=sin(angle);
int nx0=round(x0*cs-y0*sn);
int ny0=round(x0*sn+y0*cs);
int nx1=round(x1*cs-y1*sn);
int ny1=round(x1*sn+y1*cs);
drawl(nx0,ny0,nx1,ny1);
drawl(nx0,ny0,nx1*50,ny1*50);
drawl(x0+75,y0,x1+75,y1);
getch();
closegraph();
}


