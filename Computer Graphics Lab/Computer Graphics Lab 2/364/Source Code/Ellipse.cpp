#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void drawEllipse(int centerX,int centerY,int radiusX,int radiusY)
 {
    int x,y;
    float d1,d2;

    initwindow(800,600,"Scan Conversion of Ellipse");
    setcolor(WHITE);

    x=0;
    y=radiusY;
    d1=(radiusY*radiusY)-(radiusX*radiusX*radiusY)+(0.25*radiusX*radiusX);
    putpixel(centerX+x,centerY+y,WHITE);
    putpixel(centerX+x,centerY-y,WHITE);
    putpixel(centerX+x,centerY+y,WHITE);
    putpixel(centerX-x,centerY-y,WHITE);

    while((radiusX * radiusX * (y - 0.5)) > (radiusY * radiusY * (x + 1))) {
        if(d1<0)
            {
            d1+=(2*radiusY*radiusY*(x+1))+(radiusY*radiusY);
        }
        else
            {
            d1+=(2*radiusY*radiusY*(x+1))+(radiusY*radiusY)-(2*radiusX*radiusX*(y-1));
            y--;
        }
        x++;

        putpixel(centerX+x,centerY+y,WHITE);
        putpixel(centerX+x,centerY-y,WHITE);
        putpixel(centerX-x,centerY+y,WHITE);
        putpixel(centerX-x,centerY-y,WHITE);
    }

    d2=((radiusY*(x+0.5))*(radiusY*(x+0.5)))+((radiusX* (y - 1))*(radiusX* (y - 1)))-(radiusX * radiusX * radiusY * radiusY);

    while (y > 0)
     {
        if (d2 < 0)
            {
            d2+=(2 * radiusY * radiusY * (x + 1))-(2 * radiusX * radiusX * (y - 1))+(radiusX * radiusX);
            x++;
        }
         else
        {
            d2+= -(2*radiusX*radiusX*(y - 1))+(radiusX * radiusX);
        }
        y--;

        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
    }
    delay(50000);
    closegraph();
}

int main() {
    int centerX = 400;
    int centerY = 300;
    int radiusX = 200;
    int radiusY = 100;

    drawEllipse(centerX, centerY, radiusX, radiusY);
    return 0;
}
