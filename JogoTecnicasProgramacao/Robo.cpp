#include "Robo.h"
#include <stdlib.h>
#include <time.h>
//#include <iostream>
using namespace Entidades::Personagens;

Entidades::Personagens::Robo::Robo()
{
	setTextura("robo_parado.png");
	corpo.setSize(sf::Vector2f(70.f, 70.f));
	corpo.setPosition(sf::Vector2f(100.f, 100.f));
}

Entidades::Personagens::Robo::Robo(const sf::Vector2f pos)
{
	setTextura("robo_parado.png");
	corpo.setSize(sf::Vector2f(70.f, 70.f));
	corpo.setPosition(pos);
}

Entidades::Personagens::Robo::~Robo()
{
}

void Robo::setPersegue(bool per) 
{
	this->persegue = per;
}
bool Robo::getPersegue() 
{
	return persegue;
}

//void Entidades::Personagens::Robo::executar()
//{
//	Robo::imprimir();
//}
