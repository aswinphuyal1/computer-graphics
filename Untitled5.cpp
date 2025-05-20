#include <stdio.h>
#include <graphics.h>
#include <math.h>
int main()
{

    int Xr, Yr, x1, y1, p, k = 0;
    printf("Enter the x-radius of ellipse: ");
    scanf("%d", &Xr);
    printf("Enter the y-radius of ellipse: ");
    scanf("%d", &Yr);
    printf("Enter the centre coordinates of ellipse: ");
    scanf("%d %d", &x1, &y1);
    p = pow(Yr, 2) - pow(Xr, 2) * Yr + 1 / 4 * pow(Xr, 2);
    int x = 0, y = Yr;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    while (2 * Yr * Yr * x < 2 * Xr * Xr * y)
    {
        putpixel(x + x1, y + y1, 15);
        putpixel(-x + x1, y + y1, 15);
        putpixel(x + x1, -y + y1, 15);
        putpixel(-x + x1, -y + y1, 15);
        if (p < 0)
        {
            x = x + 1;
            p = p + 2 * pow(Yr, 2) * x + pow(Yr, 2);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + 2 * pow(Yr, 2) * x - 2 * pow(Xr, 2) * y + pow(Yr, 2);
        }
        delay(50);
    }

    p = Yr * Yr * (x + 1 / 2) * (x + 1 / 2) + Xr * Xr * (y - 1) * (y - 1) - Xr * Xr * Yr * Yr;
    while (y >= 0)
    {
        putpixel(x + x1, y + y1, 15);
        putpixel(-x + x1, y + y1, 15);
        putpixel(x + x1, -y + y1, 15);
        putpixel(-x + x1, -y + y1, 15);
        if (p > 0)
        {
            y = y - 1;
            p = p - 2 * pow(Xr, 2) * y + pow(Xr, 2);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + 2 * pow(Yr, 2) * x - 2 * pow(Xr, 2) * y + pow(Xr, 2);
        }
        delay(50);
    }
    getch();
    closegraph();
}

