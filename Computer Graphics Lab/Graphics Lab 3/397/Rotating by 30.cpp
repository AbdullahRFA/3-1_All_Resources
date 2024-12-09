#include <graphics.h>
#include <math.h>

int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   int x1 = 0, y1 = 0;
   int x2 = 100, y2 = 50;

   float angle = 30; // Rotation angle in degrees

   // Convert angle to radians
   float rad = angle * 3.14159 / 180.0;

   // Calculate the new coordinates after rotation
   int newX1 = x1 * cos(rad) - y1 * sin(rad);
   int newY1 = x1 * sin(rad) + y1 * cos(rad);

   int newX2 = x2 * cos(rad) - y2 * sin(rad);
   int newY2 = x2 * sin(rad) + y2 * cos(rad);

   line(x1, y1, x2, y2); // Original line
   line(newX1, newY1, newX2, newY2); // Rotated line

   getch();
   closegraph();
   return 0;
}
