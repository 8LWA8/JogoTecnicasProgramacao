#include "Jogador.h"
#include <iostream>
using namespace Entidades::Personagens;



Jogador::Jogador() 
{
    setTextura("astronauta.png");
    corpo.setSize(sf::Vector2f(50.f, 100.f));
    corpo.setPosition(sf::Vector2f(100.f, 100.f));
    vel.setVal(1.0, 1.0);
    mov = true;
}

Jogador::~Jogador()
{
}


void Jogador::executar()
{
	this->imprimir();
    pGerenteGrafico->CenterView(&coordenada);
    this->mover();
    this->resetColl();
}



void Jogador::mover()
{
    if (mov == true)
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (coll.getX() != 1.0))
        {
            corpo.move(sf::Vector2f(vel.getX(), 0.f));
            coordenada.addX(vel.getX());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (coll.getX() != -1.0))
        {
            corpo.move(sf::Vector2f(-vel.getX(), 0.f));
            coordenada.addX(-vel.getY());
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (coll.getY() != 0.0))
        {
            //TESTE
            corpo.move(sf::Vector2f(0.f, -300 * vel.getY()));
            coordenada.addY(-300 * vel.getY());
        }
        else 
        {
            sofrer_gravidade();
        }
    }


    
    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && coll.getY() != 1.0)
    {
        corpo.move(sf::Vector2f(0.f, vel.getY()));
        coordenada.addY(vel.getY());
    }*/
}

void Jogador::setPontuacao(int p)
{
    this->pontuacao = p;
}
int Jogador::getPontuacao()
{
    return pontuacao;
}
