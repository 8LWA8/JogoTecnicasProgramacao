#include "Plataforma.h"
using namespace Entidades::Obstaculos;

Entidades::Obstaculos::Plataforma::Plataforma()
{
	corpo.setFillColor(sf::Color::White);
	corpo.setSize(sf::Vector2f(12000.f, 110.f));
	corpo.setPosition(sf::Vector2f(-600.f, 300.f));

}

Entidades::Obstaculos::Plataforma::~Plataforma()
{
}
