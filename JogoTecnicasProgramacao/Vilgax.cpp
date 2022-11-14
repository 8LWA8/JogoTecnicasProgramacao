#include "Vilgax.h"
using namespace Entidades::Personagens;

Entidades::Personagens::Vilgax::Vilgax()
{
	setTextura("vilgax.png");
	corpo.setFillColor(sf::Color::White);
	corpo.setSize(sf::Vector2f(200.f, 200.f));
	corpo.setPosition(sf::Vector2f(0.f, 0.f));
}

Entidades::Personagens::Vilgax::Vilgax(const sf::Vector2f pos)
{
	setTextura("vilgax.png");
	corpo.setFillColor(sf::Color::White);
	corpo.setSize(sf::Vector2f(200.f, 200.f));
	corpo.setPosition(pos);
}

Entidades::Personagens::Vilgax::~Vilgax()
{

}