#include <lib/pen.h>

void linha(Pen &p, int lado, int rotacao){
    if(lado < 1)
        return;
    //p.setColor(rand()%255, rand()%255, rand()%255);

    p.walk(lado);
    p.right(90 * rotacao);
    //linha(p, lado - 5, 1);

    p.setColor(rand()%255, rand()%255, rand()%255);
    linha(p, lado - 5, -1);
}

void fractal(){
    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 300);

    //faz o pincel apontar pra direita
    p.setHeading(0);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(30);
    p.circle(200);
    linha(p, 100, -1);
    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractal();
    return 0;
}
