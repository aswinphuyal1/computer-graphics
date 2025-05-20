#include <graphics.h>
#include <stdio.h>
int main()
{
    int gd = DETECT, gm;
    int radius, x1, y1, p, k = 0;
    printf("Enter the radius of circle: ");
    scanf("%d", &radius);
    printf("Enter the centre coordinates of circle: ");
    scanf("%d %d", &x1, &y1);
    initgraph(&gd, &gm, (char *)"");
    p = 5 / 4 - radius;
    int x = 0, y = radius;
    while (y > x)
    {
        putpixel(x + x1, y + y1, 15);
        putpixel(-x + x1, y + y1, 15);
        putpixel(x + x1, -y + y1, 15);
        putpixel(-x + x1, -y + y1, 15);
        putpixel(y + x1, x + y1, 15);
        putpixel(-y + x1, x + y1, 15);
        putpixel(y + x1, -x + y1, 15);
        putpixel(-y + x1, -x + y1, 15);
        if (p < 0)
        {
            x = x + 1;
            p = p + 2 * x + 1;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + 2 * x + 1 - 2 * y;
        }
        delay(50);
    }
    getch();
    closegraph();
}



