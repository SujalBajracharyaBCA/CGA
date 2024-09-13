#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int maxx, maxy, midx, midy;

void axis() {
    cleardevice();
    line(midx, 0, midx, maxy);  // Y-axis
    line(0, midy, maxx, midy);  // X-axis
}

void rotateLine(int x1, int y1, int x2, int y2, float angle) {
    float rad = angle * M_PI / 180;  // Convert angle to radians
    int nx1, ny1, nx2, ny2;

    // Apply rotation matrix for the first point
    nx1 = midx + (x1 - midx) * cos(rad) - (y1 - midy) * sin(rad);
    ny1 = midy + (x1 - midx) * sin(rad) + (y1 - midy) * cos(rad);

    // Apply rotation matrix for the second point
    nx2 = midx + (x2 - midx) * cos(rad) - (y2 - midy) * sin(rad);
    ny2 = midy + (x2 - midx) * sin(rad) + (y2 - midy) * cos(rad);

    // Draw the rotated line
    line(nx1, ny1, nx2, ny2);
}

int main() {
    int x1 = 50, y1 = -100, x2 = 100, y2 = -150;  // Line endpoints
    float angle;
    int gd = DETECT, gm;

    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "");

    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy / 2;

    axis();

    // Draw original line
    line(midx + x1, midy + y1, midx + x2, midy + y2);

    printf("Enter rotation angle (in degrees): ");
    scanf("%f", &angle);

    rotateLine(midx + x1, midy + y1, midx + x2, midy + y2, angle);  // Rotate and redraw the line
    printf("After rotation");
    getch();  // Wait for user input
    
    closegraph();
    return 0;
}

