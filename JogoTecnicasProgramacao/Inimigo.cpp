#include "Inimigo.h"
#include <iostream>
using namespace Entidades::Personagens;

Inimigo::Inimigo() : movAleatorio(-1)
{
	corpo.setFillColor(sf::Color::Magenta);
	corpo.setPosition(sf::Vector2f(200.f, 200.f));
	
}

Inimigo::~Inimigo()
{
}

void Inimigo::executar()
{
	//std::cout << "INI EXE" << std::endl;
	Inimigo::imprimir();
	Inimigo::moveAleatorio();
}

void Inimigo::moveAleatorio() 
{
	
	srand(time(NULL));
	float dt = relogio.getElapsedTime().asSeconds();

	if (dt >= 1.0f) //Cada 1 segundo 
	{
		movAleatorio = rand() % 2 + 1;
	}

	if (movAleatorio == 1 && coll.getX() != 1.0) 
	{
		corpo.move(sf::Vector2f(vel.getX(), 0.f));
		coordenada.addX(0.1);
	}
	else if (coll.getX() != -1.0)
	{
		corpo.move(sf::Vector2f(-vel.getX(), 0.f));
		coordenada.addX(-0.1);
	}
}
