#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    setbkcolor(15);
    setcolor(4);               //BLUE
    rectangle(10,10,630,470);
    setcolor(9);              //RED
    rectangle(5,5,635,475);
    while(kbhit()==0)          //Condition for no key in buffer memory
    {
        for(int i=80;i>=0;i-=20)
        {
            setcolor(8);         //GREY
            circle(320,240,65);
            circle(320,240,67);
            setfillstyle(SOLID_FILL,13);      //PINK
            bar(310,30,330,360);
            setfillstyle(SOLID_FILL,6);
            bar(290,360,350,375);
            setcolor(2);
            setfillstyle(SOLID_FILL,10);
            pieslice(320,240,i,i+40,60);
            pieslice(320,240,i+120,i+160,60);
            pieslice(320,240,i+240,i+280,60);
            setcolor(4);
            circle(320,240,10);
            setfillstyle(SOLID_FILL,12);
            floodfill(320,240,4);
            delay(100);
         setcolor(0);
        setfillstyle(SOLID_FILL,0);
        pieslice(320,240,i,i+40,60);
        pieslice(320,240,i+120,i+160,60);
        pieslice(320,240,i+240,i+280,60);
        setcolor(4);
        circle(320,240,10);
        setfillstyle(SOLID_FILL,12);
        floodfill(320,240,4); }}
    getch();
    closegraph();
    return 0; }