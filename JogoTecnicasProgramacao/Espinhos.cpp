#include "Espinhos.h"
using namespace Entidades::Obstaculos;

Espinhos::Espinhos()
{
	causa_dano = true;
	this->dano = comprimento * 0.5;

	corpo.setSize(sf::Vector2f(35.f, 35.f));
	corpo.setPosition(sf::Vector2f(-400.f, 200.f));
	setTextura("espinhos.png");
}

Espinhos::Espinhos(const sf::Vector2f pos)
{
	corpo.setSize(sf::Vector2f(35.f, 35.f));
	corpo.setPosition(pos);
	setTextura("espinhos.png");
}

Espinhos::~Espinhos()
{
}
