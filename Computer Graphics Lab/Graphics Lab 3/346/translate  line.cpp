#include <graphics.h>
#include<bits/stdc++.h>

using namespace std;

void scanConvertLine(int x1, int y1, int x2, int y2, int translateX) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Translate the line
    int x1_translated = x1 + translateX;
    int x2_translated = x2 + translateX;

    // Scan convert the translated line
    line(x1_translated, y1, x2_translated, y2);

    delay(5);
    getch();
    closegraph();
}

int main() {
    // Original line coordinates
    int x1,x2,y1,y2;
    cout<<"Enter the start co-ordinates: ";
    cin>>x1>>y1;
    cout<<"Enter the End co-ordinates: ";
    cin>>x2>>y2;
//    int x1 = 0;
    //int y1 = 0;
    //int x2 = 100;
    //int y2 = 50;

    // Translation on x-axis
    int translateX = 75;

    // Scan convert the translated line
    scanConvertLine(x1, y1, x2, y2, translateX);

    return 0;
}

