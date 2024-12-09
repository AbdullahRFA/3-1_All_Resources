#include <graphics.h>
#include<bits/stdc++.h>

using namespace std;

void scanConvertLine(int x1, int y1, int x2, int y2, float scale) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Calculate the scaled coordinates
    int x1_scaled = static_cast<int>(x1 * scale);
    int y1_scaled = static_cast<int>(y1 * scale);
    int x2_scaled = static_cast<int>(x2 * scale);
    int y2_scaled = static_cast<int>(y2 * scale);

    // Scan convert the scaled line
    line(x1_scaled, y1_scaled, x2_scaled, y2_scaled);

    delay(5);
    getch();
    closegraph();
}

int main() {
    // Original line coordinates
    int x1,x2,y1,y2;
    cout<<"Enter the co-ordinates: ";
    cin>>x1>>x2>>y1>>y2;
   // int x1 = 0;
    //int y1 = 0;
   // int x2 = 100;
   // int y2 = 50;

    // Scale factor
    float scale = 0.5;

    // Scan convert the scaled line
    scanConvertLine(x1, y1, x2, y2, scale);

    return 0;
}
