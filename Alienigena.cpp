#include "Alienigena.h"
using namespace Entidades::Personagens;

Entidades::Personagens::Alienigena::Alienigena()
{
	setTextura("alien_parado.png");
	corpo.setFillColor(sf::Color::White);
	corpo.setSize(sf::Vector2f(100.f, 150.f));
	corpo.setPosition(sf::Vector2f(400.f, 100.f));
}

Entidades::Personagens::Alienigena::~Alienigena()
{
}

/*void Entidades::Personagens::Alienigena::executar()
{
	Alienigena::imprimir();
}*/
