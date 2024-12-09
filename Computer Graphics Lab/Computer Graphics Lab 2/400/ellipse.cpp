
#include <graphics.h>

int main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, ""); // Initialize graphics mode

   ellipse(300, 200, 0, 360, 100, 50); // Draw ellipse

   getch();
   closegraph(); // Close graphics mode
   return 0;
}

