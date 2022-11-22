#include "Jogador2.h"

using namespace Entidades::Personagens;

Jogador2::Jogador2()
{
    this->setId(2);
    this->setTextura("astronauta.png");
}

void Jogador2::mover()
{
    if (mov == true)
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (coll.getX() != 1.0))
        {
            corpo.move(sf::Vector2f(vel.getX(), 0.f));
            coordenada.addX(vel.getX());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (coll.getX() != -1.0))
        {
            corpo.move(sf::Vector2f(-vel.getX(), 0.f));
            coordenada.addX(-vel.getY());
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (coll.getY() != 0.0))
        {
            corpo.move(sf::Vector2f(0.f, -300 * vel.getY()));
            coordenada.addY(-300 * vel.getY());
        }
        else
        {
            sofrer_gravidade();
        }
    }
}

Jogador2 Jogador2::operator++(int)
{
    Jogador2 jog2 = *this;
    setPontuacao(getPontuacao() + 1);
    return jog2;
}
