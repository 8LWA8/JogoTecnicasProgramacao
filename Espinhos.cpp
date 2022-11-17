#include "Espinhos.h"
using namespace Entidades::Obstaculos;

Entidades::Obstaculos::Espinhos::Espinhos()
{
	causa_dano = true;
	corpo.setSize(sf::Vector2f(50.f, 50.f));
	corpo.setPosition(sf::Vector2f(-400.f, 200.f));
	setTextura("espinhos.png");
}

Entidades::Obstaculos::Espinhos::Espinhos(const sf::Vector2f pos)
{
	corpo.setSize(sf::Vector2f(50.f, 50.f));
	corpo.setPosition(pos);
	setTextura("espinhos.png");
}

Entidades::Obstaculos::Espinhos::~Espinhos()
{
}
