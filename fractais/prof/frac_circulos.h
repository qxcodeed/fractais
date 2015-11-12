#ifndef FRAC_CIRCULOS_H
#define FRAC_CIRCULOS_H
#include "lib/pen.h"
#include <cmath>

void circulos(Pen &p, float tam){
    if(tam < 1)
        return;
    double fator = 0.33;

    p.circle(tam);

    for(int i = 0; i < 6; i++){
        p.up();
        p.walk(tam);
        p.down();
        circulos(p, tam * fator);
        p.up();
        p.walk(-tam);
        p.down();
        p.left(60);
    }

}


void frac_circulos(){
    Pen pen(800, 800);
    pen.setSpeed(50);
    pen.setThickness(1);
    pen.setColor(255, 255, 255);
    pen.setXY(400, 400);
    pen.setHeading(0);
    circulos(pen, 200);
    pen.wait();
}

#endif // FRAC_CIRCULOS_H
