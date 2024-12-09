#include <iostream>
#include <cmath>
#include<graphics.h>
using namespace std;
bool clipHelper(double p, double q, double &tEnter, double &tExit) {
    if (p == 0) {
        if (q < 0) return false;
    } else {
        double t = q / p;
        if (p < 0) {
            if (t > tEnter) tEnter = t;
        } else {
            if (t < tExit) tExit = t;
        }
    }
    return true;
}
bool clipLineLiangBarsky(double x1, double y1, double x2, double y2,
                         double xmin, double ymin, double xmax, double ymax,
                         double &x1Clip, double &y1Clip, double &x2Clip, double &y2Clip) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double tEnter = 0.0;
    double tExit = 1.0;

    if (clipHelper(-dx, x1 - xmin, tEnter, tExit) &&
        clipHelper(dx, xmax - x1, tEnter, tExit) &&
        clipHelper(-dy, y1 - ymin, tEnter, tExit) &&
        clipHelper(dy, ymax - y1, tEnter, tExit)) {

        if (tExit > tEnter) {
            x1Clip = x1 + tEnter * dx;
            y1Clip = y1 + tEnter * dy;
            x2Clip = x1 + tExit * dx;
            y2Clip = y1 + tExit * dy;
            return true;
        }
    }
    return false;
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    double x1 = 200, y1 = 100, x2 = 800, y2 = 900;
    double xmin = 300, ymin = 200, xmax = 700, ymax = 800;
    double x1Clip, y1Clip, x2Clip, y2Clip;
    if (clipLineLiangBarsky(x1, y1, x2, y2, xmin, ymin, xmax, ymax, x1Clip, y1Clip, x2Clip, y2Clip)) {
        cout << "Clipped Line: (" << x1Clip << ", " << y1Clip << ") to (" << x2Clip << ", " << y2Clip << ")" << endl;
        rectangle(xmin,ymax, xmax, ymin);
        line(x1Clip,y1Clip,x2Clip,y2Clip);
    } else {
        cout << "Line lies entirely outside the clipping window." << endl;
    }
    delay(10000);
    return 0;
}