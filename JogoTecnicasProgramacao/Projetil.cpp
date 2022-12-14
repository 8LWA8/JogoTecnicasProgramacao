#include "Projetil.h"
#include "Personagem.h"
#include <iostream>

using namespace Entidades;
using namespace Entidades::Personagens;

Projetil::Projetil(sf::Vector2f pos): atingiu(false), existe(true)
{
	this->setDano(5.0f);
	corpo.setSize(sf::Vector2f(20.f, 10.f));
	corpo.setPosition(pos);
	corpo.move(sf::Vector2f(0.f, 35.f));
	setTextura("assets\\textures\\projetil.png");
	//corpo.setFillColor(sf::Color::Red);
	vel.setVal(0.2, 0.0);
	//std::cout << "criou projetil" << std::endl;
}

Entidades::Projetil::~Projetil()
{
}

void Entidades::Projetil::setAtingiu(bool a)
{
	atingiu = a;
}

bool Entidades::Projetil::getAtingiu()
{
	return atingiu;
}

void Entidades::Projetil::executar()
{
	if (existe == true)
	{
		imprimir();
		corpo.move(sf::Vector2f(-2 * vel.getX(), 0.f));
		sofrer_gravidade();
		anularGravidade();

		if (getCoord()->getX() < -600.f)
		{
			setAtingiu(true);
		}

		if (atingiu == true)
		{
			corpo.setPosition(posAlien);
			corpo.move(sf::Vector2f(0.f, 35.f));
			setAtingiu(false);
		}
	}
}

void Entidades::Projetil::setExiste(bool e)
{
	existe = e;
}

bool Entidades::Projetil::getExiste()
{
	return existe;
}

void Entidades::Projetil::danar(Entidade* ent)
{
	if (ent != NULL)
	{
		Personagem* per = dynamic_cast<Personagem*>(ent);
		per->levarDano(this->getDano());
	}
}

void Entidades::Projetil::recebePosAlien(sf::Vector2f posAli)
{
	posAlien = posAli;
}

void Entidades::Projetil::anularGravidade()
{
	corpo.move(sf::Vector2f(0.0f, -0.5f));
	coordenada.addY(-0.5);
}

void Entidades::Projetil::salvar()
{
}
