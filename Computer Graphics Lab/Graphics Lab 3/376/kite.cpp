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
drawl(300,50,100,150);
drawl(300,50,500,150);
drawl(500,150,300,350);
drawl(100,150,300,350);
//drawl(300,350,200,400);
getch();
closegraph();
}

