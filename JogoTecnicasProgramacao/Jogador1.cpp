#include "Jogador1.h"

using namespace Entidades::Personagens;

Jogador1::Jogador1() 
{
    this->setId(1);
    this->setTextura("assets\\textures\\astronauta.png");
    
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
            corpo.move(sf::Vector2f(0.f, -150 * vel.getY()));
            coordenada.addY(-150 * vel.getY());

        }
        else
        {
            sofrer_gravidade();
        }
    }

}

Jogador1 Jogador1::operator++(int)
{
    Jogador1 jog1 = *this;
    setPontuacao(getPontuacao() + 1);
    return jog1;
}