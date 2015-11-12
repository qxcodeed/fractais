#include "lib/pen.h"

enum opcao{vai = 1, volta = -1};

void dragao(Pen &p, float tam, int n, opcao op, float desl){
    if(n == 0){
        p.walk(tam);
        return;
    }
    dragao(p, tam, n - 1, vai, desl - 10);
    p.right(90 * op);
    dragao(p, tam, n - 1, volta, desl + 10);
}

void frac_dragao(){
    Pen pen(800, 800);
    pen.setSpeed(20);
    pen.setThickness(3);
    pen.setColor(255, 255, 255);
    pen.setXY(300, 250);
    pen.setHeading(0);
    dragao(pen, 10, 10, vai, 125);
    pen.wait();
}
