#include "Projetil.h"

using namespace Entidades;

Entidades::Projetil::Projetil(): atingiu(false)
{

	corpo.setSize(sf::Vector2f(20.f, 5.f));
	vel.setVal(1.0, 0.0);
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
	corpo.move(sf::Vector2f(-400 * vel.getY(), 0.f));
	
}

void Entidades::Projetil::danar(Entidade* ent)
{

}
