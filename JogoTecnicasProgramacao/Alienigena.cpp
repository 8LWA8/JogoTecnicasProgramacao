#include "Alienigena.h"
using namespace Entidades::Personagens;

Alienigena::Alienigena()
{
	setTextura("alien_parado.png");
	corpo.setSize(sf::Vector2f(50.f, 100.f));
	corpo.setPosition(sf::Vector2f(400.f, -300.f));

	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);
}

Alienigena::~Alienigena()
{
}

/*void Entidades::Personagens::Alienigena::executar()
{
	Alienigena::imprimir();
}*/


void Alienigena::setAtirou(bool estado) 
{
	this->atirou = estado;
}
bool Alienigena::getAtirou() 
{
	return this->atirou;
}
