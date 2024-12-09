
#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>
using namespace std;
int main()
{
    int gd=DETECT;
    int gm,p;
    int x1,y1;
    initgraph(&gd,&gm,"");
    cout<< "Enter the co-ordinates: ";
    cin>>x1>>y1;
    putpixel(x1,y1,RED);
     getch();
    closegraph();
}
