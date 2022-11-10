#include "Espinhos.h"
using namespace Entidades::Obstaculos;

Entidades::Obstaculos::Espinhos::Espinhos()
{
	corpo.setSize(sf::Vector2f(100.f, 100.f));
	corpo.setPosition(sf::Vector2f(-400.f, 200.f));
	setTextura("espinhos.png");
}

Entidades::Obstaculos::Espinhos::~Espinhos()
{
}
