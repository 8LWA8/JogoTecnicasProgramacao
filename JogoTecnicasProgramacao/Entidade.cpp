#include "Entidade.h"
#include <iostream>

using namespace Entidades;

Entidade::Entidade() : coordenada(0.0, 0.0),
tam(0.0, 0.0),
vel(0.1, 0.1),
coll(0.0, 0.0),
dano(0.0),
mov(false)
{
	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);

	

}

Entidade::~Entidade()
{
}

Coord* Entidade::getCoord() 
{

	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	//coordenada.setVal(corpo.getPosition().x, corpo.getPosition().y);
	return &coordenada;
};

Coord* Entidade::getTam() 
{
	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);
	return &tam;
}

Coord* Entidade::getVel() 
{
	return &vel;
}

Coord* Entidade::getColl() 
{
	return &coll;
}


void Entidade::imprimir() 
{
	pGerenteGrafico->render(&corpo);
}

void Entidade::resetColl() 
{
	coll.setVal(0.0, 0.0);
}

void Entidade::sofrer_gravidade()
{
	if (coll.getY() == 0.0)
	{
		//std::cout << "GRAVIDADE" << std::endl;
		corpo.move(sf::Vector2f(0.f, 0.5));
		coordenada.addY(0.5);
	}
}

bool Entidade::getMov() const
{
	return mov;
}

void Entidade::setMov(bool m)
{
	mov = m;
}


float Entidade::getDano() 
{
	return this->dano;
}

void Entidade::setDano(float dan) 
{
	this->dano = dan;
}