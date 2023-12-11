#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;
void bezier()
{
    int x[4],y[4],px,py;
    cout<<"Enter x and y coordinates of all control points one after the other";
    for(int i=0;i<4;i++){
        cin>>x[i]>>y[i];
    }
    double t;
    for(t=0.0;t<=1.0;t=t+0.0001){
        px=pow((1-t),3)* x[0]+3*t*pow((1-t),2)* x[1]+3*t*t*(1-t)* x[2]+pow(t,3)* x[3];
        py=pow((1-t),3)* y[0]+3*t*pow((1-t),2)* y[1]+3*t*t*(1-t)* y[2]+pow(t,3)* y[3];
        putpixel(px,py,WHITE);
    }
}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    bezier();
    getch();
    closegraph();
    return 0;
}
