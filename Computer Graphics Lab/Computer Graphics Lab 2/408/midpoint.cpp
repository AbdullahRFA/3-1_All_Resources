#include<graphics.h>
#include<math.h>
#include<stdio.h>
int main(){
    float A=300;
    float B=300;
    int Gdriver=DETECT,Gmode;
    initgraph(&Gdriver,&Gmode,"");
    float R=200;
    float x=R;
    float y=0;
    float P=4.0/5.0-R;
    putpixel(0+A,R+B,RED);
    putpixel(0+A,-R+B,RED);
    putpixel(R+A,0+B,RED);
    putpixel(A-R,0+B,RED);
    while(x>y){
        y++;
        if(P<=0){
            P=P+2*y+1;
        }else{
            x--;
            P=P=2*y-2*x+1;
        }
        if(x<y)break;
        putpixel(A+x,B+y,RED);
        putpixel(A-x,B+y,RED);
        putpixel(A+x,B-y,RED);
        putpixel(A-x,B-y,RED);
        putpixel(A+y,B+x,RED);
        putpixel(A-y,B+x,RED);
        putpixel(A+y,B-x,RED);
        putpixel(A-y,B-x,RED);
    }
    delay(10000);
    closegraph();
    return 0;
}

