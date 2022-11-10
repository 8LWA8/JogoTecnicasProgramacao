#include "Robo.h"
#include <stdlib.h>
#include <time.h>
using namespace Entidades::Personagens;

Entidades::Personagens::Robo::Robo()
{
	setTextura("robo_parado.png");
	corpo.setFillColor(sf::Color::White);
	corpo.setSize(sf::Vector2f(200.f, 200.f));
	//float nf = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 500.f));

	corpo.setPosition(sf::Vector2f(100.f, 100.f));
}

Entidades::Personagens::Robo::~Robo()
{
}

/*void Entidades::Personagens::Robo::executar()
{
	Robo::imprimir();
}*/
