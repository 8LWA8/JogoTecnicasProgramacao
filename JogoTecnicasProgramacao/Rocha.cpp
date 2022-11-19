#include "Rocha.h"
using namespace Entidades::Obstaculos;

Entidades::Obstaculos::Rocha::Rocha()
{
	setTextura("rocha.png");
	corpo.setSize(sf::Vector2f(40.f, 35.f));
	corpo.setPosition(sf::Vector2f(-600.f, 200.f));
}

Entidades::Obstaculos::Rocha::Rocha(const sf::Vector2f pos)
{
	setTextura("rocha.png");
	corpo.setSize(sf::Vector2f(40.f, 35.f));
	corpo.setPosition(pos);
}

Entidades::Obstaculos::Rocha::~Rocha()
{
}
