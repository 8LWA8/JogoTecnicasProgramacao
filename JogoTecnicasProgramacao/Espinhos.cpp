#include "Espinhos.h"

using namespace Entidades::Obstaculos;
using namespace Entidades::Personagens;

Espinhos::Espinhos()
{
	this->causa_dano = true;
	this->setDano(comprimento*0.5);
	this->setId(4);
	corpo.setSize(sf::Vector2f(35.f, 35.f));
	corpo.setPosition(sf::Vector2f(-400.f, 200.f));
	setTextura("espinhos.png");
}

Espinhos::Espinhos(const sf::Vector2f pos, const sf::Vector2f tam, float comp)
{
	comprimento = comp;
	causa_dano = true;
	this->setDano(comprimento * 0.5);
	this->setId(4);

	corpo.setSize(sf::Vector2f(tam));
	corpo.setPosition(pos);
	setTextura("espinhos.png");
}

Espinhos::~Espinhos()
{
}



void Espinhos::danar(Entidade* ent) 
{
	if (ent != NULL)
	{
		Personagem* per = dynamic_cast<Personagem*>(ent);
		per->levarDano(this->getDano());
	}
}

void Espinhos::setAltura(float l) 
{
	this->comprimento = l;
}
float Espinhos::getAltura() 
{
	return this->comprimento;
}
