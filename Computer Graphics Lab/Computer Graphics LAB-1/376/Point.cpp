#include <iostream>
using namespace std;
#include <graphics.h>

int main() {
       int x; // x-coordinate of the point
    int y ; // y-coordinate of the point
    cout<<"Enter position: ";
    cin>>x>>y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    // Set the pixel at (x, y) to a specific color
    putpixel(x, y, WHITE);

    //delay(50000); // Pause for 5 seconds
    getch();
    closegraph();
    return 0;
}
