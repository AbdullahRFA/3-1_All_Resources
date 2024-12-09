// Mahfuz Anam-374
// Dept of CSE,JU

#include <graphics.h>
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
int xmax,xmin,ymax,ymin;
int main()
{
    int gd, gm = DETECT;
	initgraph(&gd, &gm, "");

    int a,b,aa,bb,n,i,j,k,x1,x2,y1,y2;
    cout<<"Enter the Window points:"<<endl;
    cin>>a>>b>>aa>>bb;
    xmax=max(a,aa);
    xmin=min(a,aa);
    ymax=max(b,bb);
    ymin=min(b,bb);

    line(xmin,ymin,xmax,ymin);
    line(xmin,ymax,xmax,ymax);
    line(xmin,ymax,xmin,ymin);
    line(xmax,ymax,xmax,ymin);

    cout<<"Enter the number of points: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        line(x1,y1,x2,y2);
        double sx1,sy1,sx2,sy2;
        int p[4],q[4],dx,dy,f=0;
        dx = x2-x1;
        dy = y2-y1;
        p[0] = dx * (-1);  p[1] = dx;
        p[2] = dy * (-1);  p[3] = dy;
        q[0] = x1 - xmin;  q[1] = xmax - x1;
        q[2] = y1 - ymin;  q[3] = ymax - y1;

        double u1 = 0,u2 = 1;
        for(j = 0;j < 4;j++)
        {
            if(p[j] == 0)
            {
                if(q[j] < 0)
                {
                    f = 1;
                    break;
                }
            }
            else if(p[j] < 0)
            {
                u1 = max(u1,(q[j] / (double)p[j]));
            }
            else
            {
                u2 = min(u2, (q[j] / (double)p[j]));
            }
        }
        if(f == 1)
        {
            cout << "Outside\n";
        }
        else
        {
            if((u1 == 0) && (u2 == 1))
            {
                cout << "Inside\n";
            }
            else if(u1 > u2)
            {
                cout << "Outside\n";
            }
            else
            {
                sx1 = x1 + u1*dx;
                sy1 = y1 + u1*dy;
                sx2 = x1 + u2*dx;
                sy2 = y1 + u2*dy;
                cout << "End points of clipped lines are: " << sx1 << " " << sy1 << " " << sx2 << " " << sy2 << endl;
            }
        }
    }
    delay(10000);
    getch();
    closegraph();
}
