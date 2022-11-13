#include "Plataforma.h"
using namespace Entidades::Obstaculos;

Plataforma::Plataforma()
{
	
	corpo.setSize(sf::Vector2f(12000.f, 110.f));
	corpo.setPosition(sf::Vector2f(-600.f, 300.f));
	
	tam.setVal(corpo.getSize().x, corpo.getSize().y);
	coordenada.setVal(corpo.getPosition().x, corpo.getPosition().y);

}

Plataforma::~Plataforma()
{
}

void Plataforma::executar() 
{
	Plataforma::setTextura("plataforma.png");
	Plataforma::imprimir();

}