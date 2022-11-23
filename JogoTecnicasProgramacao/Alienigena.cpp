#include "Alienigena.h"
using namespace Entidades::Personagens;

Alienigena::Alienigena(const sf::Vector2f pos)//: atirou(false)
{
	this->setId(6);
	setTextura("alien_parado.png");
	corpo.setSize(sf::Vector2f(40.f, 80.f));
	corpo.setPosition(pos);

	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);

	//proj.getCorpo()->setPosition(sf::Vector2f(corpo.getPosition().x, corpo.getPosition().y));
	proj = new Projetil(sf::Vector2f(corpo.getPosition().x, corpo.getPosition().y));
}

Alienigena::~Alienigena()
{
}

void Alienigena::executar()
{
	if (vivo == true)
	{
		this->imprimir();
		this->atirar();
		this->moveAleatorio();
		this->resetColl();
	}
	else
	{
		proj->setExiste(false);
	}
}

void Alienigena::atirar()
{
	//setAtirou(true);
	proj->recebePosAlien(corpo.getPosition());
	proj->executar();
}


//void Alienigena::setAtirou(bool estado) 
//{
//	this->atirou = estado;
//}

Entidades::Projetil* Alienigena::getProj()
{
	return proj;
}


//
//bool Alienigena::getAtirou() 
//{
//	return this->atirou;
//}
