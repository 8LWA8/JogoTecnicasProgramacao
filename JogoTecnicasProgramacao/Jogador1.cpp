#include "Jogador1.h"


using namespace Entidades::Personagens;

Jogador1::Jogador1() 
{
    this->setId(1);
    this->setTextura("assets\\textures\\astronauta.png");
}

Entidades::Personagens::Jogador1::Jogador1(const sf::Vector2f pos)
{
    this->setId(1);
    this->setTextura("assets\\textures\\astronauta.png");
    this->getCorpo()->setPosition(pos);
}

Entidades::Personagens::Jogador1::~Jogador1()
{
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



