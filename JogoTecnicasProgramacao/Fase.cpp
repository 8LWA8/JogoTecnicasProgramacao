#include "Fase.h"
#include <vector>
#include <list>

using namespace Personagens;
using namespace Obstaculos;

namespace Fases{

	

	Fase::Fase() : jogador1(NULL), jogador2(NULL),  LEnt(), Ger(/*&LEnt*/)
{

	this->getCorpo()->setSize(sf::Vector2f(2100.0f, 1900.0f));
	this->getCorpo()->setPosition(sf::Vector2f(-700.0f, -500.0f));
	this->setTextura("assets//textures//background.jpg");

	criaRobos();
	criaRochas();
	criaPoderes();
	criaJogadores();
	/*
	Ger.incluirJogador(&jogador1);
	Ger.incluirJogador(&jogador2);
	Ger.incluirObstaculo(&chao);
	*/
}
	
	
	
Fase::~Fase()
{
	LEnt.limpaLista();
	Ger.getVecInimigos()->erase(Ger.getVecInimigos()->begin(), Ger.getVecInimigos()->end());

}


void Fase::criaRobos()
{
	//sorteia quantos inimigos (entre 3 e 5)

	int n = 3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		Robo* r1 = new Robo(sf::Vector2f(-600.f + 100.f*i, 100.f));
		Entidade* e1 = static_cast <Entidade*>(r1);
		LEnt.addEntidade(e1);
		Inimigo* i1 = static_cast <Inimigo*>(r1);
		Ger.getVecInimigos()->push_back(i1);
	}
}

void Fase::criaRochas()
{
	int n = 3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		Rocha* r1 = new Rocha(sf::Vector2f(-600.f + 100.f * i, 0.f));
		Entidade* e1 = static_cast <Entidade*>(r1);
		LEnt.addEntidade(e1);
		Obstaculo* o1 = static_cast <Obstaculo*>(r1);
		Ger.getListObst()->push_back(o1);
	}
}

void Fase::criaPoderes()
{
	int n = 3 + rand() % 4;
	for (int i = 0; i < n; i++)
	{
		EsferaPoder* esfera = new EsferaPoder(sf::Vector2f(-550.f + 150.f * i, 150.f));
		Entidade* e1 = static_cast <Entidade*>(esfera);
		LEnt.addEntidade(e1);
		Ger.getVecPoder()->push_back(esfera);
	}
}

void Fase::criaJogadores() 
{
	if (jogador1 == NULL && jogador2 == NULL) {
		jogador1 = new Jogador1();
		jogador2 = new Jogador2();

		LEnt.addEntidade(jogador1);
		LEnt.addEntidade(jogador2);
		Ger.getVecJogs()->push_back(jogador1);
		Ger.getVecJogs()->push_back(jogador2);
	}

}

Jogador1* Fase::getJog1() 
{
	if (jogador1 != NULL) 
	{
		return jogador1;
	}
	std::cout << "ERROR: ponteiro NULL" << std::endl;
	return NULL;
}
Jogador2* Fase::getJog2() {
	if (jogador2 != NULL)
	{
		return jogador2;
	}
	std::cout << "ERROR: ponteiro NULL" << std::endl;
	return NULL;
}

int Fase::getPontTotal() 
{
	
	if (this->jogador1 != NULL && this->jogador2 != NULL) 
	{
		return (jogador1->getPontuacao() + jogador2->getPontuacao());

	}
	else if (this->jogador2 == NULL) 
	{
		return this->jogador1->getPontuacao();
	}
}

}

