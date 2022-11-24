#include "Espinhos.h"

using namespace Entidades::Obstaculos;
using namespace Entidades::Personagens;

Espinhos::Espinhos()
{
	this->causa_dano = true;
	this->setDano(altura * 0.1);
	this->setId(4);
	corpo.setSize(sf::Vector2f(35.f, 35.f));
	corpo.setPosition(sf::Vector2f(-400.f, 200.f));
	setTextura("espinhos.png");
}

Espinhos::Espinhos(const sf::Vector2f pos, const sf::Vector2f tam, float altu)
{
	altura = altu;
	causa_dano = true;
	this->setDano(altura * 0.1);
	this->setId(4);

	corpo.setSize(sf::Vector2f(tam));
	corpo.setPosition(pos);
	setTextura("espinhos.png");
}

Espinhos::~Espinhos()
{
}



void Espinhos::danar(Entidade* ent) 
{
	if (ent != NULL)
	{
		Personagem* per = dynamic_cast<Personagem*>(ent);
		per->levarDano(this->getDano());
	}
}

void Entidades::Obstaculos::Espinhos::salvar()
{
	std::ofstream dadosEspi;

	dadosEspi.open("salvar/salvarEspi.txt", std::ios::app);

	if (!dadosEspi.is_open())
	{
		std::cout << "ERRO ABRINDO salvarEspi.txt" << std::endl;
		exit(1);
	}

	std::cout << "entrou salvar espinhos" << std::endl;

	dadosEspi << getId() << " ";
	dadosEspi << corpo.getPosition().x << " ";
	dadosEspi << corpo.getPosition().y << " ";
	dadosEspi << getAltura() << " ";

	dadosEspi << std::endl;
	dadosEspi.close();

}

void Espinhos::setAltura(float l) 
{
	this->altura = l;
}
float Espinhos::getAltura() 
{
	return this->altura;
}
