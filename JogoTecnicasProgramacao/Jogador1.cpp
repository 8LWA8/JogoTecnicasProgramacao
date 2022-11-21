#include "Jogador1.h"

using namespace Entidades::Personagens;

Jogador1::Jogador1() 
{
    this->setTextura("astronauta.png");
}

void Jogador1::mover()
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

Jogador1 Jogador1::operator++(int)
{
    Jogador1 jog1 = *this;
    this->setPontuacao(this->getPontuacao() + 1);
    return jog1;
}