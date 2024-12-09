#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
    int gd=DETECT,gm,a,b,x1,y1,x2,y2;
    double p1,p2,c,s;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    setcolor(GREEN);

    setbkcolor(WHITE);
    printf("Enter coordinates of line: ");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    line(x1,y1,x2,y2);
    cout<<"Enter The translate value:"<<endl;
    cin>>p1;
    x1+=p1;
    x2+=p1;

    line(x1,y1,x2,y2);
    getch();
    closegraph();

    return 0;


}



