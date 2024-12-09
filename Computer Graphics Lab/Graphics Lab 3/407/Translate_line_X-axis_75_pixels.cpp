#include <iostream>
#include <conio.h>
#include <graphics.h>

using namespace std;
int main()
{
    printf("\t\t***********Program for translating line on X-axis by 75 pixels*********** \n");
    int gd=DETECT,gm,x1,x2,y1,y2,tx,ty;
    initgraph(&gd,&gm,"C:\\Tc\\BGI");
    cout<<"Enter the first co-ordinate of a line:";
    cin>>x1>>y1;
    cout<<"Enter the second co-ordinate of a line:";
    cin>>x2>>y2;
    line(x1,y1,x2,y2);
    cout<<"Enter the translation vector:";
    cin>>tx;
    setcolor(RED);
    x1=x1+tx;
    x2=x2+tx;
    line(x1,y1,x2,y2);
    getch();
    closegraph();
}

