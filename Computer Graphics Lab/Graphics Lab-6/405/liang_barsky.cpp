#include <iostream>
#include <graphics.h>
#include"graphics.h"
#include <iostream>
using namespace std;

struct Point {
    double x, y;
};

void liangBarsky(Point p1, Point p2, double xMin, double yMin, double xMax, double yMax) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;

    double p[4] = {-dx, dx, -dy, dy};
    double q[4] = {p1.x - xMin, xMax - p1.x, p1.y - yMin, yMax - p1.y};

    double t1 = 0.0, t2 = 1.0;

    for (int i = 0; i < 4; ++i) {
        if (p[i] == 0) {
            if (q[i] < 0) {
                cout << "Line is outside the clipping window." << endl;
                return;
            }
        } else {
            double t = q[i] / p[i];
            if (p[i] < 0) {
                t1 = max(t1, t);
            } else {
                t2 = min(t2, t);
            }
        }
    }

    if (t1 > t2) {
        cout << "Line is outside the clipping window." << endl;
    } else {
        double clippedX1 = p1.x + t1 * dx;
        double clippedY1 = p1.y + t1 * dy;
        double clippedX2 = p1.x + t2 * dx;
        double clippedY2 = p1.y + t2 * dy;

        cout << "Clipped Line: (" << clippedX1 << ", " << clippedY1 << ") to (" << clippedX2 << ", " << clippedY2 << ")" << endl;
    }
}

int main() {
    Point p1 = {30, 40};
    Point p2 = {80, 90};
    Point A = {-4, 2};
    Point B = {-1, 7};
    Point C = {-1, 5};
    Point D = {3, 8};
    Point E = {-2, 3};
    Point F = {1, 2};
    Point G = {1, -2};
    Point H = {3, 3};
    Point I = {-4, 7};
    Point J = {-2, 10};
    double xMin = -3, yMin = 1, xMax = 2, yMax = 6;

    liangBarsky(A, B, xMin, yMin, xMax, yMax);
    liangBarsky(C, D, xMin, yMin, xMax, yMax);
    liangBarsky(E, F, xMin, yMin, xMax, yMax);
    liangBarsky(G, H, xMin, yMin, xMax, yMax);
    liangBarsky(I, J, xMin, yMin, xMax, yMax);


    return 0;
}

