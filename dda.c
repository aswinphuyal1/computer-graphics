#include<stdio.h>
#include<graphics.h>
#include<math.h>

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;

    // Determine the number of steps needed
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    // Calculate increments for x and y
    float xIncrement = dx / (float) steps;
    float yIncrement = dy / (float) steps;

    // Initialize the starting point
    float x = x1;
    float y = y1;

    // Plot the first point
    putpixel(round(x), round(y), WHITE);

    // Draw the line
    for (int i = 1; i <= steps; i++) {
        x += xIncrement;
        y += yIncrement;
        putpixel(round(x), round(y), WHITE);
    }
}

int main() {
    int x1, y1, x2, y2;

    // Input the coordinates of the two points
    printf("Enter x1 y1: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter x2 y2: ");
    scanf("%d %d", &x2, &y2);

    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw the line using DDA algorithm
    drawLineDDA(x1, y1, x2, y2);

    // Wait for a key press and close the graphics window
    getch();
    closegraph();

    return 0;
}