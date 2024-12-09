#include<graphics.h>
#include<iostream>
using namespace std;
int main(){
    int Gdriver=DETECT,Gmode;
    int x;scanf("%d",&x);
    int x_rad;scanf("%d",&x_rad);
    int y;scanf("%d",&y);
    int y_rad;scanf("%d",&y_rad);
    int start_angle;scanf("%d",&start_angle);
    int end_angle;scanf("%d",&end_angle);
    initgraph(&Gdriver,&Gmode,"");
    ellipse(x,y,start_angle,end_angle,x_rad,y_rad);
    delay(10000);
    closegraph();
    return 0;
}
