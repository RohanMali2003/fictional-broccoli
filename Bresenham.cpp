#include <iostream>
#include <graphics.h>
using namespace std;

void drawline(int x0, int y0, int x1, int y1){
    int dx, dy, p, x, y;
    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;
    p = 2 * dy - dx;
    while (x < x1)
    {
        if (p >= 0)
        {   putpixel(x, y, 7);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;}
        else
        {   putpixel(x, y, 7);
            p = p + 2 * dy;}
        x = x + 1;
}}

int main()
{
    int gdriver = DETECT, gmode, error, x0, y0, x1, y1;
    initgraph(&gdriver, &gmode, NULL);
    x0=200, x1=300;
    y0=300, y1=200;
    drawline(x0, y0, x1, y1);
    getch();  // Wait for a key press
    closegraph();
    return 0;
}