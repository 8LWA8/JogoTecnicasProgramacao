#include "Plataforma.h"
using namespace Entidades::Obstaculos;

Plataforma::Plataforma()
{
	this->setId(5);
	this->getCorpo()->setSize(sf::Vector2f(1200.f, 60.f));
	this->getCorpo()->setPosition(sf::Vector2f(-600.f, 300.f));
	this->setTextura("plataforma.png");
	this->setMov(false);
	
	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);
	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	

}

Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f tamanho)
{
	this->setId(5);
	this->getCorpo()->setSize(tamanho);
	this->getCorpo()->setPosition(pos);
	this->setTextura("plataforma.png");
	this->setMov(false);

	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);
	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	
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

void Entidades::Obstaculos::Plataforma::salvar()
{
}
