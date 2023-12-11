#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

class Fractals
{
public:
    void fractals(int x1, int y1, int x5, int y5, int i)
    {
        int segment_x = (x5 - x1);
        int segment_y = (y5 - y1);
        int x2 = x1 + segment_x;
        int y2 = y1 + segment_y;
        int x4 = x1 + 2 * (segment_x);
        int y4 = y1 + 2 * (segment_y);
        int x3 = (int)(0.5 * (x1 + x5) - sqrt(3) * (y5 - y1) / 6);
        int y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * (x5 - x1) / 6);
        if (i == 0)
        {
            line(x1, y1, x5, y5);
        }
        else
        {
            fractals(x1, y1, x2, y2, i - 1);
            fractals(x2, y2, x3, y3, i - 1);
            fractals(x3, y3, x4, y4, i - 1);
            fractals(x4, y4, x5, y5, i - 1);
        }
    }
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    Fractals f;
    f.fractals(100, 100, 200, 200, 2);
    getch();
    closegraph();
    return 0;
}