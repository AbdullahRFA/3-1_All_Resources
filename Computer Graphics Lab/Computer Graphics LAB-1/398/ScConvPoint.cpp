#include<bits/stdc++.h>
#include<graphics.h>
int main()
{
    float x,y;
    printf("Enter X co-ordinate = ");
    scanf("%f",&x);
    printf("Enter Y co-ordinate = ");
    scanf("%f",&y);

    int gd= DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    putpixel(floor(x),floor(y),WHITE);
    getch();
    closegraph();
}
