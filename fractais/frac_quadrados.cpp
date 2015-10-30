#include "cpen.h"

void square(float x, float y, float lado){
    //pen_set_color(rand()%255,rand()%255,rand()%255 );
    pen_set_xy(x, y);
    pen_set_heading(0);
    pen_walk(lado);
    pen_right(90);
    pen_walk(lado);
    pen_right(90);
    pen_walk(lado);
    pen_right(90);
    pen_walk(lado);
}

void fractal(int x, int y, float lado){
    square(x, y, lado);
    if(lado < 10)
        return;


    float tam = lado * 0.46;


    fractal(x - tam/2, y - tam/2, tam);
    fractal(x + lado - tam/2, y - tam/2, tam);
    fractal(x - tam/2, y + lado - tam/2, tam);
    fractal(x + lado - tam/2, y + lado  - tam/2, tam);
}

void quadrados(){
    pen_open(1000, 800);
    pen_set_back_color(0, 100, 100);
    pen_set_thickness(1);
    pen_set_speed(100);
    fractal(180, 180, 350);
    pen_wait();
    pen_close();
}

int main(){
    quadrados();
    return 0;
}
