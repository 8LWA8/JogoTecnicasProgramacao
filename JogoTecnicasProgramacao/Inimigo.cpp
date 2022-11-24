#include "Inimigo.h"
#include <iostream>
using namespace Entidades::Personagens;

Inimigo::Inimigo() : movAleatorio(-1)
{
	this->setId(2);
	this->setDano(0.5);
	this->setMov(true);

	corpo.setPosition(sf::Vector2f(200.f, 200.f));	
	vel.setVal(0.1, 0.1);
	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);
}

Inimigo::~Inimigo()
{
}

void Inimigo::executar()
{
	//std::cout << "INI EXE" << std::endl;
	if (vivo == true)
	{
		this->imprimir();
		this->moveAleatorio();
		this->resetColl();
	}
}

std::string Entidades::Personagens::Inimigo::salvar()
{
	return "";
}

void Inimigo::moveAleatorio() 
{
	
	srand(time(NULL));
	float dt = relogio.getElapsedTime().asSeconds();
	
	if (dt >= 2.0f) //Cada 2 segundos
	{
		movAleatorio = rand() % 2 + 1;
	}

	sofrer_gravidade();

	if (movAleatorio == 1 && (coll.getX() != 1.0))
	{
		corpo.move(sf::Vector2f(vel.getX(), 0.f));
		coordenada.addX(vel.getX());
	}
	else if (coll.getX() != -1.0)
	{
		corpo.move(sf::Vector2f(-vel.getX(), 0.f));
		coordenada.addX(-vel.getX());
	}

	
}

void Inimigo::danar(Entidade* ent)
{
	if (ent != NULL) 
	{
		Personagem* per = dynamic_cast<Personagem*>(ent);
		per->levarDano(this->getDano());
	}

}

void Inimigo::levarDano(float dano) 
{
}