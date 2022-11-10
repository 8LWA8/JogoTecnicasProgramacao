#include "Rocha.h"
using namespace Entidades::Obstaculos;

Entidades::Obstaculos::Rocha::Rocha()
{
	setTextura("rocha.png");
	corpo.setSize(sf::Vector2f(110.f, 100.f));
	corpo.setPosition(sf::Vector2f(-600.f, 200.f));
}

Entidades::Obstaculos::Rocha::~Rocha()
{
}
