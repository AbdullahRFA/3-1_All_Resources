#include <iostream>
#include <graphics.h>

void liangBarsky(double x1, double y1, double x2, double y2, double xmin, double ymin, double xmax, double ymax) {
    double dx = x2 - x1, dy = y2 - y1;
    double p[4] = {-dx, dx, -dy, dy};
    double q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};
    double t_in = 0.0, t_out = 1.0;

    for (int i = 0; i < 4; ++i) {
        if (p[i] == 0 && q[i] < 0) {
            std::cout << "Line is outside of the clipping window." << std::endl;
            return;
        } else if (p[i] != 0) {
            double t = q[i] / p[i];
            if (p[i] < 0) {
                t_in = std::max(t_in, t);
            } else if (p[i] > 0) {
                t_out = std::min(t_out, t);
            }
        }
    }

    if (t_in > t_out) {
        std::cout << "Line is outside of the clipping window." << std::endl;
    } else {
        double new_x1 = x1 + t_in * dx;
        double new_y1 = y1 + t_in * dy;
        double new_x2 = x1 + t_out * dx;
        double new_y2 = y1 + t_out * dy;

        line(new_x1, new_y1, new_x2, new_y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    double x1 = 50, y1 = 50, x2 = 200, y2 = 200;
    double xmin = 100, ymin = 100, xmax = 300, ymax = 300;

    rectangle(xmin, ymin, xmax, ymax);
    liangBarsky(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

    delay(5000); // Pause for 5 seconds

    closegraph();
    return 0;
}
