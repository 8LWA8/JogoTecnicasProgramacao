#include "Projetil.h"
#include "Personagem.h"
using namespace Entidades;
using namespace Entidades::Personagens;

Projetil::Projetil(): atingiu(false)
{

	corpo.setSize(sf::Vector2f(20.f, 5.f));
	vel.setVal(1.0, 0.0);
}

Entidades::Projetil::~Projetil()
{
}

void Projetil::setAtingiu(bool a)
{
	atingiu = a;
}

bool Projetil::getAtingiu()
{
	return atingiu;
}

void Entidades::Projetil::executar()
{
	imprimir();
	corpo.move(sf::Vector2f(-400 * vel.getY(), 0.f));
	
}

void Projetil::danar(Entidade* ent)
{
	if (ent != NULL)
	{
		Personagem* per = dynamic_cast<Personagem*>(ent);
		per->levarDano(this->getDano());
	}
}
