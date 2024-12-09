#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main()
{
    int x,y;
    cout<<"Enter position: ";
    cin>>x>>y;
    int gd= DETECT,gm;
    initgraph(&gd,&gm,"");
    putpixel(x,y,WHITE);
    getch();
    closegraph();
    return 0;
}
