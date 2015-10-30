#include <lib/pen.h>

void linha(Pen &p, int lado){

    if(lado < 5)
        return;
    p.setColor(rand()%255, rand()%255, rand()%255);

    p.walk(lado);
    p.right(90);
    linha(p, lado - 5);
}


int main(){
    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(50, 50);

    //faz o pincel apontar pra direita
    p.setHeading(0);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(30);
    linha(p, 500);
    //espera clicar no botao de fechar
    p.wait();

}
