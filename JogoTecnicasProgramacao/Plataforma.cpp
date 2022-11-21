#include "Plataforma.h"
using namespace Entidades::Obstaculos;

Plataforma::Plataforma()
{
	
	corpo.setSize(sf::Vector2f(1200.f, 60.f));
	corpo.setPosition(sf::Vector2f(-600.f, 300.f));
	
	this->mov = false;
	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);
	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	this->setTextura("plataforma.png");

}

Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f tamanho)
{
	corpo.setSize(tamanho);
	corpo.setPosition(pos);

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
	this->anularGravidade();

}

void Plataforma::anularGravidade() 
{
	if (flutua) 
	{
		corpo.move(sf::Vector2f(0.0f, 2.0f));
	}
}

void Plataforma::setFlutua(bool f)
{
	this->flutua = f;
}
bool Plataforma::getFlutua() 
{
	return flutua;
}