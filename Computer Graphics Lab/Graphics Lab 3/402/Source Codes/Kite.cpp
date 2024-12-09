#include<time.h>
#include<graphics.h>
int main() {
    int gd = DETECT,gm;
    int x = 10,y = 480;
    initgraph(&gd,&gm,(char*)"");
    while(!kbhit()){
        cleardevice();
        if(y==0) {
            y=rand()%480;
            x=rand()%640;
        }
        else {
            y=y-1;
            x=x+1;
            line(x-50,y,x,y-70);
            line(x,y-70,x+50,y);
            line(x+50,y,x,y+70);
            line(x,y+70,x-50,y);
            line(x,y-70,x,y+70);
            line(x,y+70,x+10,y+140);
            line(x,y+70,x-10,y+140);
            line(x-50,y,x+50,y);
            line(x,y,x+130,y+640);
        }
        delay(20);
    }
    closegraph();
    restorecrtmode();
}
