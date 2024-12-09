#include <iostream>
#include<graphics.h>
using namespace std;

bool clipLineLiangBarsky(double x1, double y1, double x2, double y2, double xmin, double ymin, double xmax, double ymax, double& x1Out, double& y1Out, double& x2Out, double& y2Out) {
    double p[4] = {-x2 + x1, x2 - x1, -y2 + y1, y2 - y1};
    double q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    double u1 = 0.0, u2 = 1.0;

    for (int i = 0; i < 4; ++i) {
        if (p[i] == 0) {
            if (q[i] < 0)
                return false;
        } else {
            double t = q[i] / p[i];
            if (p[i] < 0)
                u1 = max(u1, t);
            else
                u2 = min(u2, t);
        }
    }

    if (u1 > u2)
        return false;

    x1Out = x1 + u1 * (x2 - x1);
    y1Out = y1 + u1 * (y2 - y1);
    x2Out = x1 + u2 * (x2 - x1);
    y2Out = y1 + u2 * (y2 - y1);

    return true;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    double xmin = -3.0*10;
    double ymin = 1.0*10;
    double xmax = 2.0*10;
    double ymax = 6.0*10;
    int i;
    double a[10][10],x1,y1,x2,y2;
 ///   initwindow(800, 600, "Line Clipping");
    cout<<"Input line points"<<endl;
    for(i=0;i<5;i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
    }
    for(i=0;i<5;i++)
    {

    double clipped_x1, clipped_y1, clipped_x2, clipped_y2;
     x1=a[i][0]*10;
     y1=a[i][1]*10;
     x2=a[i][2]*10;
     y2=a[i][3]*10;
    if (clipLineLiangBarsky(x1, y1, x2, y2, xmin, ymin, xmax, ymax, clipped_x1, clipped_y1, clipped_x2, clipped_y2)) {
        cout << "Clipped Line: (" << clipped_x1 << ", " << clipped_y1 << ") to (" << clipped_x2 << ", " << clipped_y2 << ")" << endl;
    } else {
        cout << "Line is outside the clipping window." << endl;
    }
    }
 ///   initwindow(800, 600, "Line Clipping");
    rectangle(xmin, ymin, xmax, ymax);
    for(i=0;i<5;i++)
    {
        line(a[i][0]*10,a[i][1]*10,a[i][2]*10,a[i][3]*10);
	///	delay(500);
    }
    delay(500);
	getch();
	closegraph();
    return 0;
}
