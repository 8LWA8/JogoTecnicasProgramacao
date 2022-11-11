#include "Inimigo.h"

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

	if (movAleatorio == 1) 
	{
		corpo.move(sf::Vector2f(0.1f, 0.f));
		coordenada.x += 0.1;
	}
	else 
	{
		corpo.move(sf::Vector2f(-0.1f, 0.f));
		coordenada.x -= 0.1;
	}
}
