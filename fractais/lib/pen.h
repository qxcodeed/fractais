#ifndef PEN_H
#define PEN_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

#include <ctime>
#include <cstdlib>

#define _USE_MATH_DEFINES
#include <cmath>
#include "sfLine.h"

using namespace sf;
using namespace std;

class Pen{

public:

    Pen(int largura, int altura);
    Pen(const Pen &p);

    ~Pen();

    void walk(float distance);

    void rotate(float angulo);

    //vira pra esquerda
    void left(float angulo) {rotate(-angulo);}
    //vira pra direita
    void right(float angulo){rotate(angulo);}

    //vai para essa posicao da tela
    void move(float x, float y);

    //espera tantos segundos
    void wait(int seconds);

    //espera ate clicar em fechar
    void wait();

    void setColor(sf::Color color);

    void setColor(int R, int G, int B);
    void setBackColor(int R, int G, int B){
        backGroundColor = sf::Color(R, G, B);
    }


    void clear(){
        while(!tracos.empty())
            tracos.pop_back();
    }

    void up(){ isDown = false; }
    void down(){ isDown = true; }

    void circle(float radius);

    static int rand();

    //GETTERS and SETTERS


    void  setXY         (float x, float y){ pos.x = x; pos.y = y;   }
    void  setHeading    (float angulo)    { heading   = angulo;     }
    void  setSpeed      (int velocidade)  { speed     = velocidade; }
    void  setThickness  (int espessura)   { thickness = espessura;  }

    float getX()        { return pos.x;	    }
    float getY()        { return pos.y;	    }
    int   getSpeed()    { return speed;     }
    float getHeading()  { return heading;   }
    int   getThickness(){ return thickness; }

protected:
    Clock clock;
    static int init;
    static vector <sfLine> tracos;
    enum {FRAMERATE = 60};
    RenderWindow *janela;

    Vector2f pos;
    float heading{0};
    bool isDown{true};
    Color color{Color::White};
    Color backGroundColor{Color::Black};

    unsigned thickness{1};

    //Janela *janela;
    int speed{10};

    void make_y_path(Vector2f a, Vector2f b, vector<Vector2f> & path);
    void make_x_path(Vector2f a, Vector2f b, vector<Vector2f> & path);
    vector<Vector2f> make_path(Vector2f a, Vector2f b);

    //void drawPoint(Vector2i point, int espessura);

    static void sleep(int msec);
};

#endif // PEN_H
