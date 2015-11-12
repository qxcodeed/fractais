#include "lib/pen.h"
#include <cmath>

void gelo(Pen &p, float tam){
    if(tam < 1)
        return;
    double fator = 0.3;
    p.setColor(255, 0, 0);
    for(int i = 0; i < 5; i++){
        p.setColor(0, 255, 0);
        p.walk(tam);
        gelo(p, tam * fator);
        p.setColor(0, 100, 255);
        p.walk(-tam);
        p.left(360.0/5.0);
    }

}


void frac_gelo(){
    Pen pen(800, 800);
    pen.setSpeed(30);
    pen.setThickness(3);
    pen.setColor(255, 255, 255);
    pen.setXY(400, 400);
    pen.setHeading(0);
    gelo(pen, 200);
    pen.wait();
}
