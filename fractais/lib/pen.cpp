#include "pen.h"
#include <iostream>
using namespace std;

//Inicializando os membros estaticos
vector <sfLine> Pen::tracos;
int Pen::init = 0;

void Pen::make_y_path(Vector2f a, Vector2f b, vector<Vector2f> &path)
{
    double x, y = a.y;
    double d=(b.x - a.x)/(b.y - a.y);
    while(1)//controle de parada e incremento no corpo do laco
    {
        x = a.x + (d*(y - a.y));
        //fn(x, y, param);
        path.push_back(Vector2f(x, y));

        if(a.y < b.y)
        {
            if(y >= b.y)
                return;
            y++;
        }
        if(a.y > b.y)
        {
            if(y <= b.y)
                return;
            y--;
        }
    }
}

void Pen::make_x_path(Vector2f a, Vector2f b, vector<Vector2f> &path)
{
    double x = a.x, y;
    double d=(b.y - a.y)/(b.x - a.x);
    while(1)
    {
        y = a.y + (d*(x - a.x));
        //fn(x, y, param);
        path.push_back(Vector2f(x, y));

        if(a.x < b.x)
        {
            if(x >= b.x)
                return;
            x++;
        }
        if(a.x > b.x)
        {
            if(x <= b.x)
                return;
            x--;
        }
    }
}

vector<Vector2f> Pen::make_path(Vector2f a, Vector2f b)
{
    vector<Vector2f> path;
    if(a.x == b.x && a.y == b.y){
        path.push_back(Vector2f(a.x, a.y));
        return path;
    }

    if( fabs(a.x - b.x) > fabs(a.y - b.y) )
        make_x_path(a, b, path);
    else
        make_y_path(a, b, path);
    return path;
}

int Pen::rand(){
    static int init = 1;
    if(init == 1){
        init = 0;
        std::srand(time(NULL));
    }
    return std::rand();
}

Pen::Pen(int largura, int altura):
    pos(largura/2, altura/2)
{
    if(init == 0){
        init = 1;
        janela = new RenderWindow();
        janela->create(VideoMode(largura, altura), "Pintor");
        janela->setFramerateLimit(FRAMERATE);

        janela->clear(backGroundColor);
    }
}

//desabilitando construtor de copia
Pen::Pen(const Pen &other):
    pos(other.pos),
    heading(other.heading),
    isDown(other.isDown),
    color(other.color),
    thickness(other.thickness),
    speed(other.speed)
{ }

Pen::~Pen(){delete janela;}


void Pen::move(float x, float y){
    vector<Vector2f> path = make_path(pos, Vector2f(x, y));
    static long cont = 0;
    if(isDown)
        tracos.push_back(sfLine(path.front(), path.back(), this->thickness, this->color));

    if(speed > 0){
        for (size_t i = 0; i < path.size() - 1; i++, cont++){

            sf::Event event;
            while (janela->pollEvent(event))
            {
                // Request for closing the window
                if (event.type == sf::Event::Closed)
                    janela->close();
                if(event.type == sf::Event::Resized)
                    janela->setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            }

            //drawPoint(Vector2i(path[i].x, path[i].y), thickness);
            tracos.back().setEnd(path[i]);

            janela->draw(tracos.back());
            if(cont % speed == 0){
                janela->display();
            }

            //reprintando tudo
            if(clock.getElapsedTime() > sf::milliseconds(500)){
                clock.restart();
                janela->clear(backGroundColor);
                for(const auto& elem : tracos){
                    janela->draw(elem);
                }
                janela->display();
            }
        }

    }

    pos.x = x;
    pos.y = y;
}

void Pen::walk(float distance){
    float x = pos.x + distance * std::cos(heading * M_PI/180);
    float y = pos.y - distance * std::sin(heading * M_PI/180);
    move(x, y);
}

void Pen::rotate(float angulo){
    heading -= angulo;
}

void Pen::wait(int seconds){
    sf::sleep(sf::milliseconds(seconds * 1000));
}

void Pen::wait(){

    while(janela->isOpen()){
        sf::Event event;
        while (janela->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                janela->close();
            if(event.type == sf::Event::Resized)
                janela->setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        }
        janela->clear(backGroundColor);
        for(const auto& elem : tracos){
            janela->draw(elem);
        }
        janela->display();
        sf::sleep(sf::milliseconds(100));
    }
}

void Pen::setColor(sf::Color color)
{
    this->color = color;
}

void Pen::setColor(int R, int G, int B){
    color = Color(R, G, B);
}

