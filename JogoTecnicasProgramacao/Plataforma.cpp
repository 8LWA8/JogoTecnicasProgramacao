#include "Plataforma.h"
using namespace Entidades::Obstaculos;

Plataforma::Plataforma()
{
	
	corpo.setSize(sf::Vector2f(12000.f, 110.f));
	corpo.setPosition(sf::Vector2f(-600.f, 300.f));

}

Plataforma::~Plataforma()
{
}

void Plataforma::executar() 
{
	Plataforma::setTextura("plataforma.png");
	Plataforma::imprimir();

}