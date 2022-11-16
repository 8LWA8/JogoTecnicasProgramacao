#include "Inimigo.h"
#include <iostream>
using namespace Entidades::Personagens;

Inimigo::Inimigo() : movAleatorio(-1)
{
	mov = true;
	mov_dir = true;
	mov_esq = true;
	corpo.setPosition(sf::Vector2f(200.f, 200.f));	
	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);
}

Inimigo::~Inimigo()
{
}

void Inimigo::executar()
{
	//std::cout << "INI EXE" << std::endl;
	this->imprimir();
	this->moveAleatorio();
	this->resetColl();
	
}

void Inimigo::moveAleatorio() 
{
	
	srand(time(NULL));
	float dt = relogio.getElapsedTime().asSeconds();

	if (dt >= 1.0f) //Cada 1 segundo 
	{
		movAleatorio = rand() % 2 + 1;
	}

	if (coll.getY() == 0.0) 
	{
		corpo.move(sf::Vector2f(0.f, 1.0f));
		coordenada.addY(1.0);
	}

	if (movAleatorio == 1) 
	{
		corpo.move(sf::Vector2f(vel.getX(), 0.f));
		coordenada.addX(vel.getX());
	}
	else 
	{
		corpo.move(sf::Vector2f(-vel.getX(), 0.f));
		coordenada.addX(-vel.getX());
	}

}
