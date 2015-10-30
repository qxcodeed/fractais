#include <iostream>
#include "lib/pen.h"
using namespace std;

void arvore(Pen & p, float tam){
    float fator = 0.7;
    float ang = 35;

    if (tam < 10)
        return;
	//anda pra frente
    p.setThickness(pow(tam, 1.0/2.5));
    p.setColor(p.rand()%255, p.rand()%255, p.rand()%255);
    p.walk (tam);
	//direita
	p.rotate(-ang);
    arvore(p, tam * fator);
    p.rotate(ang);
	//frente
    arvore(p, tam * fator);
	//esquerda
    p.rotate(ang); arvore(p, tam * fator); p.rotate(-ang);
	//anda pra tras
	p.walk(-tam);
}


void arvore()
{
    Pen pen(800, 800);
    pen.setSpeed(0);
    pen.setXY(400, 750);
    pen.setHeading(90);
    arvore(pen, 200);

    pen.wait();
}

//int main(){
//    arvore();
//    return 0;
//}

