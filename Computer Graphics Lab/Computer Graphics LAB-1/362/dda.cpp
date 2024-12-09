#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void drawLine(int x0,int y0,int x1,int y1)
{
    int dx=x1-x0;
    int dy=y1-y0;

    int step= abs(dx)> abs(dy)?abs(dx):abs(dy);

    float xinc= static_cast<float>(dx)/step;
    float yinc= static_cast<float>(dy)/step;
    float x=x0;
    float y=y0;

    for(int i=0;i<=step;++i)
    {
        //cout<<"("<<round(x)<<","<< round(y)<<")"<< endl;
        putpixel(static_cast<int>(x),static_cast<int>(y),WHITE);
        x+=xinc;
        y+=yinc;
    }
}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    int x0,y0,x1,y1;
    cout<<"starting point : ";
    cin>>x0>>y0;
    cout<<"ending point : ";
    cin>>x1>>y1;
    //cout<<"line coordinates: "<<endl;
    drawLine(x0,y0,x1,y1);
    delay(50000000);
    closegraph();
    return 0;
}
