#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;
void drawLine(int x1,int y1,int x2,int y2)
{
    int dx = x2-x1;
    int dy = y2-y1;
    int steps, k;
    float x_inc, y_inc;
    float x = x1;
    float y = y1;

    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else
        steps=abs(dy);

    x_inc = dx/ (float)steps;
    y_inc = dy/ (float)steps;

    putpixel(x,y,WHITE);

    for(k=0; k<steps; k++)
    {
        x=x+x_inc;
        y=y+y_inc;
        putpixel(floor(x),floor(y),WHITE);
    }
    getch();
}
void liangBarsky(float x1, float y1, float x2, float y2, float x_min, float y_min, float x_max, float y_max)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float p1 = -dx;
    float p2 = dx;
    float p3 = -dy;
    float p4 = dy;

    float q1 = x1 - x_min;
    float q2 = x_max - x1;
    float q3 = y1 - y_min;
    float q4 = y_max - y1;

    float r1 = q1 / p1;
    float r2 = q2 / p2;
    float r3 = q3 / p3;
    float r4 = q4 / p4;

    float u1 = fmaxf(0, fmaxf(fminf(r1, r2), fminf(r3, r4)));
    float u2 = fminf(1, fminf(fmaxf(r1, r2), fmaxf(r3, r4)));

    if (u1 > u2)
    {
        printf("Line is outside the clipping window.\n");
    }
    else
    {
        float x1_new = x1 + u1 * dx;
        float y1_new = y1 + u1 * dy;
        float x2_new = x1 + u2 * dx;
        float y2_new = y1 + u2 * dy;

        if(x1_new==x1 && y1_new==y1 && x2_new==x2 && y2_new==y2)
            cout<<"The line is completely inside the border"<<endl;
        else
            printf("Clipped Line: (%.2f, %.2f) to (%.2f, %.2f)\n", x1_new, y1_new, x2_new, y2_new);
    }
}

int main()
{
    float x1,y1,x2,y2,x_max,y_max,x_min,y_min;

    x_min=-3;
    y_min=1;
    x_max=2;
    y_max=6;

    float x[]={-4,-1,-1,3,-2,1,1,3,-4,-2};
    float y[]={2,7,5,8,3,2,-2,3,7,10};
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawLine(x_min,y_min,x_max,y_min);
    getch();


    for(int i=0;i<9;i=i+2)
    {
        cout<<"For Point "<<x[i]<<" "<<y[i]<<" "<<"and "<<x[i+1]<<" "<<y[i+1]<<" ";
        liangBarsky(x[i],y[i],x[i+1],y[i+1],x_min,y_min,x_max,y_max);
    }



}
