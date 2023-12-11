#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;
class CS{
private:
    int xmin,xmax,ymin,ymax,TOP,BOTTOM,LEFT,RIGHT,INSIDE;
public:
    CS()
    {
        xmin=100;
        ymin=100;
        xmax=300;
        ymax=300;
        TOP=8;
        BOTTOM=4;
        RIGHT=2;
        LEFT=1;
        INSIDE=0;
        rectangle(xmin,ymax,xmax,ymin);
    }
    void ddaline(int x1,int y1, int x2, int y2,int color, int del);
    int assignment(int x1, int y1);
    void LineClip(int x1, int y1, int x2, int y2);
};
void CS::ddaline(int x1,int y1, int x2, int y2, int color, int del){
int dx=(x2-x1);
int dy=(y2-y1);
int steps;
if(abs(dx)>abs(dy)){
    steps=abs(dx);
}
else{
    steps=abs(dy);
}
float xincr=float(dx)/steps;
float yincr=float(dy)/steps;
int x=x1;
int y=y1;
for(int i=0;i<steps;i++){
    x+=xincr;
    y+=yincr;
    putpixel(x,y,color);
    delay(del);
}}
int CS::assignment(int x1, int y1){
int A= INSIDE;
if(x1<xmin){
    A|=LEFT;
}
else if(x1>xmax){
    A|=RIGHT;
}
if(y1<ymin){
    A|=BOTTOM;
}
else if(y1>ymax){
    A|=TOP;
}
return A;
}
void CS::LineClip(int x1, int y1, int x2, int y2){
int code1=assignment(x1,y1);
int code2=assignment(x2,y2);
int x,y;
bool flag=false;
while(true){
if(code1==0 && code2==0){
    flag=true;
    break;
}
else if((code1 & code2)!=0){
 break;
}
else{
    int code;
    if(code1!=0){
        code=code1;
    }
    else{
        code=code2;
    }
if(code & TOP){                //code&top !=0 ====> (code&top)
 x=x1+(x2-x1)*(ymax-y1)/(y2-y1);
 y=ymax;
}
if(code & BOTTOM){       //code&bottom !=0 ====> (code&bottom)
 x=x1+(x2-x1)*(ymin-y1)/(y2-y1);
 y=ymin;
}
if(code & LEFT){
    y=y1+(y2-y1)*(xmin-x1)/(x2-x1);
    x=xmin;
}
if(code & RIGHT){
    y=y1+(y2-y1)*(xmax-x1)/(x2-x1);
    x=xmax; }
if(code==code1){
    x1=x;
    y1=y;
    code1=assignment(x1,y1); }
else{
    x2=x;
    y2=y;
    code2=assignment(x2,y2);
}}}
if (flag){
    ddaline(x1,y1,x2,y2,RED,10);
}}
int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    CS c1;
    c1.ddaline(400,400,200,200,WHITE,0);
    c1.LineClip(400,400,200,200);
    getch();
    closegraph();
    return 0;}
