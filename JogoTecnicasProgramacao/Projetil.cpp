#include "Projetil.h"
#include "Personagem.h"
#include <iostream>

using namespace Entidades;
using namespace Entidades::Personagens;

Entidades::Projetil::Projetil(sf::Vector2f pos): atingiu(false)
{
	corpo.setSize(sf::Vector2f(20.f, 5.f));
	corpo.setPosition(pos);
	corpo.move(sf::Vector2f(0.f, 35.f));
	corpo.setFillColor(sf::Color::Red);
	vel.setVal(0.2, 0.0);
	std::cout << "criou projetil" << std::endl;
}

Entidades::Projetil::~Projetil()
{
}

void Entidades::Projetil::setAtingiu(bool a)
{
	atingiu = a;
}

bool Entidades::Projetil::getAtingiu()
{
	return atingiu;
}

void Entidades::Projetil::executar()
{

	imprimir();
	corpo.move(sf::Vector2f(-2 * vel.getX(), 0.f));

	
}

void Entidades::Projetil::danar(Entidade* ent)
{
	if (ent != NULL)
	{
		Personagem* per = dynamic_cast<Personagem*>(ent);
		per->levarDano(this->getDano());
	}
}
