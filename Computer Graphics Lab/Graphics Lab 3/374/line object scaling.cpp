#include <iostream>
#include <conio.h>
#include <graphics.h>
using namespace std;
int main()
{
    int gd=DETECT,gm;
    float p,q,r,s,Sx,Sy;

    initgraph(&gd,&gm,"C:\\Tc\\BGI");

    cout<<"Enter the first coordinate of a line:";
    cin>>p>>q;
    cout << endl;

    cout<<"Enter the second coordinate of a line:";
    cin>>r>>s;
    cout << endl;

    line(p,q,r,s);

    cout<<"Enter the scaling factor:";
    cin>>Sx>>Sy;
    cout << endl;

    p=p*Sx;
    q=q*Sy;
    r=r*Sx;
    s=s*Sy;
    cout<<p<<" "<<q<<" "<<r<<" "<<s;
    line(p,q,r,s);

    getch();
    closegraph();
}
