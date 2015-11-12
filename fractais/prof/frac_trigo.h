#include <iostream>
#include "lib/pen.h"
using namespace std;

void trigo(Pen & p, float tam){
    if(tam < 1)
        return;
    float prop = 0.3;
    float ang = 30;
    for(int i = 0; i < 4; i++){
        p.setColor(255, 0, 0);
        p.walk(tam);
        p.right(ang);
        trigo(p, tam * prop);
        p.left(ang);
    }
    for(int i = 0; i < 4; i++){
        p.left(ang);
        trigo(p, tam * prop);
        p.right(ang);
        p.setColor(255, 255, 0);
        p.walk(-tam);
    }
}


void frac_trigo()
{
    Pen pen(800, 800);
    //pen.setBackColor(255, 255, 255);
    pen.setThickness(3);
    pen.setSpeed(50);
    pen.setXY(400, 750);

    pen.setHeading(90);
    trigo(pen, 100);

    pen.wait();
}


