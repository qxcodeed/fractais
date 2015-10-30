#include <iostream>
#include "Pen.h"


using namespace std;

void quadrado(Pen &p, int lado){
    int i = 4;
    while(i--){
        p.walk(lado);
        p.rotate(90);
        p.clear();
    }
}

void poligono(Pen &p, int nlados, int lado){
    int i = nlados;
    while(i--){
        p.walk(lado);
        p.rotate(360/nlados);
    }
}

int main()
{
    Pen pen(800, 800);
    pen.setSpeed(10);
    quadrado(pen, 300);
    poligono(pen, 8, 200);
    pen.wait(3);
    return 0;
}

