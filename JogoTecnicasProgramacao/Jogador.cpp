#include "Jogador.h"

using namespace Entidades::Personagens;

Jogador::Jogador() 
{
    setTextura("astronauta.png");
    corpo.setSize(sf::Vector2f(50.f, 100.f));
    corpo.setPosition(sf::Vector2f(100.f, 100.f));
    vel.setVal(1.0, 1.0);
}

Jogador::~Jogador()
{
}


void Jogador::executar()
{
    mover();
	pGerenteGrafico->CenterView(&coordenada);
	imprimir();
}



void Jogador::mover()
{
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (coll.getX() != 1.0) )
    {
        corpo.move(sf::Vector2f(vel.getX(), 0.f));
        coordenada.addX(vel.getX());
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (coll.getX() != -1.0) )
    {
        corpo.move(sf::Vector2f(-vel.getX(), 0.f));
        coordenada.addX(-vel.getY());
    }
    float y = coordenada.getY();
  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && coll.getY() != -1.0)
    {
        //TESTE
        corpo.move(sf::Vector2f(0.f, -vel.getY()));
        coordenada.addY(-vel.getY());
    }
    else if (coll.getY() == 0.0) 
    {
        corpo.move(sf::Vector2f(0.f, 0.5));
        coordenada.addY(0.5);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        corpo.move(sf::Vector2f(0.f, vel.getY()));
        coordenada.addY(vel.getY());
    }
}

