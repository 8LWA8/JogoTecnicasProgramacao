#include "Plataforma.h"
using namespace Entidades::Obstaculos;

Plataforma::Plataforma()
{
	
	corpo.setSize(sf::Vector2f(1200.f, 110.f));
	corpo.setPosition(sf::Vector2f(-100.f, 300.f));
	
	this->mov = false;
	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);
	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
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

void Plataforma::setFlutua(bool f)
{
	this->flutua = f;
}
bool Plataforma::getFlutua() 
{
	return flutua;
}