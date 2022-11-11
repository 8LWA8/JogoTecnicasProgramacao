#include "Jogador.h"

using namespace Entidades::Personagens;

Jogador::Jogador()
{
    setTextura("astronauta.png");
    corpo.setSize(sf::Vector2f(100.f, 150.f));
    corpo.setPosition(sf::Vector2f(100.f, 100.f));
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        corpo.move(sf::Vector2f(0.1f, 0.f));
		coordenada.x += 0.1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        corpo.move(sf::Vector2f(-0.1f, 0.f));
		coordenada.x -= 0.1;
    }
	if (coordenada.y < 50) 
	{
		corpo.move(sf::Vector2f(0.f, 0.1f));
		coordenada.y += 0.1;
	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
		//TESTE
        corpo.move(sf::Vector2f(0.f, -0.1f));
		coordenada.y -= 0.1;
    }
	/*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        corpo.move(sf::Vector2f(0.f, 0.1f));
		coordenada.y += 0.1;
    }*/
}

