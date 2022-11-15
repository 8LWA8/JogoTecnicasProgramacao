#include "Vilgax.h"
using namespace Entidades::Personagens;

Vilgax::Vilgax()
{
	//setTextura("vilgax.png");
	corpo.setSize(sf::Vector2f(200.f, 200.f));
	corpo.setPosition(sf::Vector2f(0.f, 0.f));
}

Vilgax::Vilgax(const sf::Vector2f pos)
{
	//setTextura("vilgax.png");
	corpo.setSize(sf::Vector2f(200.f, 200.f));
	corpo.setPosition(pos);
}

Vilgax::~Vilgax()
{

}