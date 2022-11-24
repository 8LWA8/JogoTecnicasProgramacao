#include "Vilgax.h"
using namespace Entidades::Personagens;

Vilgax::Vilgax():poder_dano(2.0)
{
	this->setDano(0.5 * poder_dano);
	setTextura("vilgax.png");
	corpo.setSize(sf::Vector2f(150.f, 150.f));
	corpo.setPosition(sf::Vector2f(0.f, 0.f));
}

Vilgax::Vilgax(const sf::Vector2f pos):poder_dano(2.0)
{
	this->setDano(0.5 * poder_dano);
	setTextura("vilgax.png");
	corpo.setSize(sf::Vector2f(150.f, 150.f));
	corpo.setPosition(pos);
}

Vilgax::~Vilgax()
{

}

std::string Entidades::Personagens::Vilgax::salvar()
{
	return "";
}

void Vilgax::setPoderDano(float d)
{
	this->poder_dano = d;
}
float Vilgax::getPoderDano() 
{
	return poder_dano;
}