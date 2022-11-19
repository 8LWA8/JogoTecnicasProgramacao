#include "Espinhos.h"

using namespace Entidades::Obstaculos;
using namespace Entidades::Personagens;

Espinhos::Espinhos()
{
	causa_dano = true;
	this->dano = comprimento * 0.5;

	corpo.setSize(sf::Vector2f(35.f, 35.f));
	corpo.setPosition(sf::Vector2f(-400.f, 200.f));
	setTextura("espinhos.png");
}

Espinhos::Espinhos(const sf::Vector2f pos, const sf::Vector2f tam, float comp)
{
	comprimento = comp;
	causa_dano = true;
	this->dano = comprimento/50;

	corpo.setSize(sf::Vector2f(tam));
	corpo.setPosition(pos);
	setTextura("espinhos.png");
}

Espinhos::~Espinhos()
{
}

const bool Espinhos::getCausa_dano()
{
	return causa_dano;
}

void Espinhos::danar(Entidade* ent) 
{
	if (ent != NULL)
	{
		Personagem* per = dynamic_cast<Personagem*>(ent);
		per->levarDano(this->getDano());
	}
}
