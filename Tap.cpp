#include <iostream>
#include <graphics.h>
using namespace std;

void bfill(int x, int y, int bclr, int fillclr) {
    int middle_colour = getpixel(x, y);
    if (middle_colour != bclr && middle_colour != fillclr) {
        putpixel(x, y, fillclr);
        bfill(x + 1, y, bclr, fillclr);
        bfill(x - 1, y, bclr, fillclr);
        bfill(x, y + 1, bclr, fillclr);
        bfill(x, y - 1, bclr, fillclr);
    }
}

void floodfill(int x1, int y1, int oldclr, int fillclr) {
    int current_colour = getpixel(x1, y1);
    if (current_colour == oldclr) {
        putpixel(x1, y1, fillclr);
        floodfill(x1 + 1, y1, oldclr, fillclr);
        floodfill(x1 - 1, y1, oldclr, fillclr);
        floodfill(x1, y1 + 1, oldclr, fillclr);
        floodfill(x1, y1 - 1, oldclr, fillclr);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    line(100, 100, 100, 75);
    line(100, 100, 250, 100);
    line(100, 75, 150, 75);
    line(150, 75, 150, 50);
    line(150, 50, 125, 50);
    line(125, 50, 125, 25);
    line(125, 25, 200, 25);
    line(200, 25, 200, 50);
    line(200, 50, 175, 50);
    line(175, 50, 175, 75);
    line(175, 75, 275, 75);
    line(275, 75, 275, 125);
    line(250, 100, 250, 125);
    line(275, 125, 265, 125);
    line(250, 125, 265, 125);
    line(225, 250, 290, 250);
    line(290, 250, 290, 165);
    line(225, 250, 225, 165);
    line(225, 165, 290, 165);
    line(257, 125, 267, 125);
    line(257, 125, 257, 165);
    line(267, 125, 267, 165);
    line(257, 165, 267, 165);

    bfill(264, 145, WHITE, LIGHTBLUE);
    delay(750);
    bfill(250, 200, WHITE, LIGHTBLUE);

    getch();
    closegraph();
    return 0;
}