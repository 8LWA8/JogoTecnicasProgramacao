#include "Vilgax.h"
using namespace Entidades::Personagens;

Vilgax::Vilgax():poder_dano(1.0)
{
	this->dano = dano * poder_dano;
	setTextura("vilgax.png");
	corpo.setSize(sf::Vector2f(200.f, 200.f));
	corpo.setPosition(sf::Vector2f(0.f, 0.f));
}

Vilgax::Vilgax(const sf::Vector2f pos):poder_dano(1)
{
	setTextura("vilgax.png");
	corpo.setSize(sf::Vector2f(200.f, 200.f));
	corpo.setPosition(pos);
}

Vilgax::~Vilgax()
{

}

void Vilgax::setPoderDano(float d) 
{
	this->poder_dano = d;
}
float Vilgax::getPoderDano() 
{
	return poder_dano;
}