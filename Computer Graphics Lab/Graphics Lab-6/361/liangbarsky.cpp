#include<stdio.h>
#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;

int sign(int a)
{
    if(a<0)return -1;
    else if(a>0)return 1;
    else return 0;
}

void bresenhamLine(double x1, double y1, double x2, double y2, int c)
{
    int xp,yp,ds,dt,d,xp1,xp2,yp1,yp2,dx,dy,s1,s2,interchange=0,i;
    xp1=floor(x1+0.5);
    yp1=floor(y1+0.5);
    xp2=floor(x2+0.5);
    yp2=floor(y2+0.5);
    dx=abs(xp2-xp1);
    dy=abs(yp2-yp1);
    s1=sign(xp2-xp1);
    s2=sign(yp2-yp1);
    if(dy>dx)
    {
        swap(dy,dx);
        interchange=1;
    }
    dt=2*(dy-dx);
    ds=2*dy;
    d=2*dy-dx;
    putpixel(xp1,yp1,c);
    xp=xp1;
    yp=yp1;
    for(i=1;i<=dx;i++)
    {
        if(d<0)
        {
            if(interchange==1)yp+=s2;
            else xp+=s1;
            d+=ds;
        }
        else
        {
            yp+=s2;
            xp+=s1;
            d+=dt;
        }
        putpixel(xp,yp,c);
    }
}

int main()
{
    int xmin,xmax,ymin,ymax,x,y,i,cl[]={0,1,2,3,4,5},j;
    string s,st[15];
    pair<int,int>point[15],p[5];
    cout<<"Enter the lower-left hand corner of the window: ";
    cin>>xmin>>ymin;
    cout<<"Enter the upper-right hand corner of the window: ";
    cin>>xmax>>ymax;
    for(i=1;i<=10;i++)
    {
        cout<<"Enter point "<<i<<": ";
        cin>>x>>y;
        point[i].first=x;
        point[i].second=y;
    }
    for(i=1;i<=10;i+=2)
    {
        int f=1,dx,dy;
        double u1=0.0,u2=1.0,r;
        dx=point[i+1].first-point[i].first;
        dy=point[i+1].second-point[i].second;
        p[0].first=-dx;
        p[0].second=point[i].first-xmin;
        p[1].first=dx;
        p[1].second=xmax-point[i].first;
        p[2].first=-dy;
        p[2].second=point[i].second-ymin;
        p[3].first=dy;
        p[3].second=ymax-point[i].second;
        for(j=0;j<4;j++)
        {
            //cout<<p[j].first<<" "<<p[j].second<<"##\n";
            if(p[j].first==0)
            {
                if(p[j].second>=0)continue;
                else
                {
                    f=-1;
                    break;
                }
            }
            else
            {
                r=((double)p[j].second)/((double)p[j].first);
                //cout<<r<<"^^^^\n";
                if(p[j].first<0.0)u1=max(u1,r);
                if(p[j].first>0.0)u2=min(u2,r);
            }
        }
        //cout<<u1<<" "<<u2<<"****\n";
        if(u1>u2)f=-1;
        if(f==-1)cout<<"Line with points "<<i<<" and "<<i+1<<" is completely invisible.\n";
        else
        {
            if(u1==0.0&&u2==1.0)cout<<"Line with points "<<i<<" and "<<i+1<<" is completely visible.\n";
            else
            {
                cout<<"Line with points "<<i<<" and "<<i+1<<" is visible candidate.\n";
                cout<<"Starting point of clipped line is: ("<<point[i].first+dx*u1<<", "<<point[i].second+dy*u1<<")\n";
                cout<<"Ending point of clipped line is: ("<<point[i].first+dx*u2<<", "<<point[i].second+dy*u2<<")\n";
            }
        }
        cout<<"************************\n";
    }
    initwindow(1000,600);
    rectangle(xmin,ymax,xmax,ymin);
    j=1;
    for(i=1;i<=10;i+=2)
    {
        bresenhamLine(point[i].first,point[i].second,point[i+1].first,point[i+1].second,cl[j]);
        j++;
    }
    getch();
    return 0;
}


