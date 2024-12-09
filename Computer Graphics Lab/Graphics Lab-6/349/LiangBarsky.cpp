//Liang-Barsky Algorithm
#include <stdio.h>
#include<math.h>
#include <graphics.h>
struct point
{
    int x =0;
    int y =0;
};

struct fraction
{
    int a = 1;
    int b = 1;
};

int xMin = -3, xMax = 2, yMin = 1, yMax = 6;
point P1, P2;
int isVisible( point P, point Q)
{
    P1 = P, P2 =Q;
    int p[6], q[6];
    fraction r[6];
    p[1] = (Q.x - P.x)*(-1);
    p[2] =  p[1]*(-1);
    p[3] = (Q.y - P.y)*(-1);
    p[4] = p[3]*(-1);
    q[1] = P.x - xMin;
    q[2] = xMax - P.x;
    q[3] = P.y - yMin;
    q[4] = yMax - P.y;

    for(int i=1; i<=4; i++)
    {
        if(p[i]==0 && q[i]<0)
        {
            return 0;
        }
    }

    fraction u1, u2;
    u1.a = 0, u1.b=0;
    u2.a =1, u2.b =1;
    for(int i=1; i<=4; i++)
    {
        r[i].a = q[i];
        r[i].b = p[i];
        if(q[i]<0 && p[i]<0)
        {
            r[i].a = r[i].a*(-1);
            r[i].b = r[i].b*(-1);
        }
        if(p[i]<0)
        {
            if(r[i].a>0 && r[i].b>0)
            {
                if(u1.a<r[i].a)
                {
                    u1 = r[i];
                }
                else if(u1.a == r[i].a && u1.b > r[i].b)
                {
                    u1 = r[i];
                }
            }
        }
        else if(p[i]>0)
        {
            float s , t;
            if(r[i].a ==0 || r[i].b ==0)
            {
                s=0;
            }
            else
            {
                s = r[i].a/r[i].b;
            }
            if(u2.a ==0 || u2.b ==0)
            {
                t=0;
            }
            else
            {
                t = u2.a/u2.b;
            }
            if(s<t)
            {
                u2 = r[i];
            }
        }
    }

    float c, d;
    if(u1.b==0 || u1.a==0)
    {
        c=0;
    }
    else
    {
        c = (float)u1.a/u1.b;
    }
    if(u2.b==0 || u2.a==0)
    {
        d=0;
    }
    else
    {
        d = (float)u2.a/u2.b;
    }

    if(c>d)
    {
        return 0;
    }
    else
    {
        if((u1.a ==0 && u1.b ==0) && (u2.a ==1 && u2.b ==1))
        {
             P1 =P;
             P2 =Q;
             return 1;
        }
        else
        {
            if(u1.a!=0 && u1.b!=0)
            {
                int z;
                if(p[2]!=0)
                {
                    z = (p[2]*u1.a)/u1.b;
                if(((p[2]*u1.a)%u1.b)!=0)
                {
                    if(z<0)
                    {
                        z--;
                    }
                    else
                    {
                        z++;
                    }
                }
                P1.x =  P.x + z;
                }
                if(p[4]!=0)
                {
                    z = (p[4]*u1.a)/u1.b;
                if(((p[4]*u1.a)%u1.b)!=0)
                {
                    if(z<0)
                    {
                        z--;
                    }
                    else
                    {
                        z++;
                    }
                }
                P1.y =  P.y + z;
                }
            }
            if(u2.a !=0 && u2.b!=0)
            {
                int z;
                if(p[2]!=0)
                {
                    z = (p[2]*u2.a)/u2.b;
                if(((p[2]*u2.a)%u2.b)!=0)
                {
                    if(z<0)
                    {
                        z--;
                    }
                    else
                    {
                        z++;
                    }
                }
                P2.x =  P.x + z;
                }
                if(p[4]!=0)
                {
                    z = (p[4]*u2.a)/u2.b;
                if(((p[4]*u2.a)%u2.b)!=0)
                {
                    if(z<0)
                    {
                        z--;
                    }
                    else
                    {
                        z++;
                    }
                }
                P2.y =  P.y + z;
                }
            }
            return 1;
        }
    }
}
int main()
{
    point A, B, C, D, E, F, G, H, I, J;
    A.x = -4, A.y = 2;
    B.x = -1, B.y = 7;
    C.x = -1, C.y = 5;
    D.x = 3, D.y = 8;
    E.x = -2, E.y = 3;
    F.x = 1, F.y = 2;
    G.x = 1, G.y = -2;
    H.x = 3, H.y = 3;
    I.x = -4, I.y = 7;
    J.x = -2, J.y = 10;

    int flag;
    printf("The given boundary of the frame is xMin = %d, xMax = %d, yMin = %d, yMax = %d\n\n", xMin, xMax, yMin, yMax);
    printf("The gives lines are: \n");
    printf("point A(%d, %d) to point B(%d, %d)\n", A.x, A.y, B.x, B.y);
    printf("point C(%d, %d) to point D(%d, %d)\n", C.x, C.y, D.x, D.y);
    printf("point E(%d, %d) to point F(%d, %d)\n", E.x, E.y, F.x, F.y);
    printf("point G(%d, %d) to point H(%d, %d)\n", G.x, G.y, H.x, H.y);
    printf("point I(%d, %d) to point J(%d, %d)\n\n", I.x, I.y, J.x, J.y);

    printf("After execution of Liang Barsky algorihtm.. \n");
    flag = isVisible(A, B);
    if(flag == 0)
    {
        printf("Line AB is not visible in the frame.\n");
    }
    else if(flag == 1)
    {
        printf("Endpoints of the clipped line of AB is (%d, %d) and (%d, %d)\n", P1.x, P1.y, P2.x, P2.y);
    }

    flag = isVisible(C, D);
    if(flag == 0)
    {
        printf("Line CD is not visible in the frame.\n");
    }
    else if(flag == 1)
    {
        printf("Endpoints of the clipped line of CD is (%d, %d) and (%d, %d)\n", P1.x, P1.y, P2.x, P2.y);
    }

    flag = isVisible(E, F);
    if(flag == 0)
    {
        printf("Line EF is not visible in the frame.\n");
    }
    else if(flag == 1)
    {
        printf("Endpoints of the clipped line of EF is (%d, %d) and (%d, %d)\n", P1.x, P1.y, P2.x, P2.y);
    }

    flag = isVisible(G, H);
    if(flag == 0)
    {
        printf("Line GH is not visible in the frame.\n");
    }
    else if(flag == 1)
    {
        printf("Endpoints of the clipped line of GH is (%d, %d) and (%d, %d)\n", P1.x, P1.y, P2.x, P2.y);
    }

    flag = isVisible(I, J);
    if(flag == 0)
    {
        printf("Line IJ is not visible in the frame.\n");
    }
    else if(flag == 1)
    {
        printf("Endpoints of the clipped line of IJ is (%d, %d) and (%d, %d)\n", P1.x, P1.y, P2.x, P2.y);
    }

    return 0;
}



