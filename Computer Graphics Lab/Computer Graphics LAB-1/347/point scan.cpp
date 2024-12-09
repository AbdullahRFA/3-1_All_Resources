#include<iostream>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
using namespace std;
int main()
{
int x0,y0,x1,y1,i,x,y;
cout<<"Enter first coordinate"<<endl;
cin>>x0>>y0;
int gr=DETECT,gm;
initgraph(&gr,&gm,"C:\\TURBOC3\\BGI");
putpixel(x0,y0,RED);
getch();
closegraph();
return 0;
}
