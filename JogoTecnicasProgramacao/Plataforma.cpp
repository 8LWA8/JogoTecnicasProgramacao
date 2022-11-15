#include "Plataforma.h"
using namespace Entidades::Obstaculos;

Plataforma::Plataforma()
{
	
	corpo.setSize(sf::Vector2f(1200.f, 110.f));
	corpo.setPosition(sf::Vector2f(-100.f, 300.f));
	
	tam.setVal(corpo.getSize().x, corpo.getSize().y);
	coordenada.setVal(corpo.getPosition().x, corpo.getPosition().y);
	this->setTextura("plataforma.png");

}

Plataforma::~Plataforma()
{
}

void Plataforma::executar() 
{
	
	this->imprimir();
	this->resetColl();

}