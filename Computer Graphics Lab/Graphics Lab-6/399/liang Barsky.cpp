#include <stdio.h>
#include<windows.h>

typedef struct {
    int x;
    int y;
} Point;

void liangBarskyLineClip(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    float t1 = 0, t2 = 1;
    int dx = x2 - x1, dy = y2 - y1;

    int p[4] = {-dx, dx, -dy, dy};
    int q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0 && q[i] < 0) {
            printf("Line Segment (%d, %d) to (%d, %d) is completely outside the clipping window.\n",
                   x1, y1, x2, y2);
            return;
        }

        if (p[i] != 0) {
            float t = (float)q[i] / p[i];
            if (p[i] < 0) {
                if (t > t1) t1 = t;
            } else {
                if (t < t2) t2 = t;
            }
        }
    }

    if (t1 <= t2) {
        int x_start = x1 + t1 * dx;
        int y_start = y1 + t1 * dy;
        int x_end = x1 + t2 * dx;
        int y_end = y1 + t2 * dy;

        printf("Line Segment (%d, %d) to (%d, %d) is partially inside the clipping window.\n",
               x_start, y_start, x_end, y_end);

        Point intersection1 = {x_start, y_start};
        Point intersection2 = {x_end, y_end};

        printf("Intersection Point 1: (%d, %d)\n", intersection1.x, intersection1.y);
        printf("Intersection Point 2: (%d, %d)\n", intersection2.x, intersection2.y);
    } else {
        printf("Line Segment (%d, %d) to (%d, %d) is completely outside the clipping window.\n",
               x1, y1, x2, y2);
    }
}

int main() {
    int xmin, ymin, xmax, ymax;

    printf("Enter the coordinates of the rectangular window (xmin ymin xmax ymax): ");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

    int lineSegments[10][4] = {
        {-4, 2, 1, 7},
        {-1, 4, 2, 8},
        {3, 6, 0, 3},
        {-5, 2, 4, 5},
        {0, 0, -2, 2},
        {2, 6, 0, 4},
        {1, -1, 3, 2},
        {-2, -1, -5, 2},
        {2, 4, -1, 1},
        {0, 7, 1, 2}
    };

    for (int i = 0; i < 10; i++) {
           // Sleep(300);
        printf("\nChecking Line Segment %d:\n", i + 1);
        liangBarskyLineClip(lineSegments[i][0], lineSegments[i][1],
                            lineSegments[i][2], lineSegments[i][3],
                            xmin, ymin, xmax, ymax);
    }

    return 0;
}
