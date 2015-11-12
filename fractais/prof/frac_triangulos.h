#ifndef FRAC_TRIANGULOS_H
#define FRAC_TRIANGULOS_H
#include "lib/pen.h"

struct Par{
    int x, y;
    Par(int _x, int _y){
        x = _x;
        y = _y;
    }
    Par operator+(const Par &other){
       return Par(x + other.x, y + other.y);
    }
    Par operator/(float f){
        return Par(x/f, y/f);
    }
};

void triangulo(Par A, Par B, Par C, Pen &p){
    p.setXY(A.x, A.y);
    p.move(B.x, B.y);
    p.move(C.x, C.y);
    p.move(A.x, A.y);
}

void sierpinski(Par A, Par B, Par C, Pen &p, int nivel){
    triangulo(A, B, C, p);
    if (nivel > 0){
        sierpinski(A, (A + B)/2, (A + C)/2, p, nivel - 1);
        sierpinski(B, (B + A)/2, (B + C)/2, p, nivel - 1);
        sierpinski(C, (C + A)/2, (C + B)/2, p, nivel - 1);
    }
}

void frac_triangulo(){
    Pen pen(800, 800);
    pen.setSpeed(30);
    pen.setThickness(3);
    pen.setColor(255, 255, 255);
    pen.setXY(400, 400);
    pen.setHeading(0);
    sierpinski(Par(100, 700), Par(350, 200), Par(600, 700), pen, 6);
    pen.wait();
}

#endif // FRAC_TRIANGULOS_H
