#include "Fase_Segunda.h"

using namespace Fases;
#include <iostream>
Fases::Fase_Segunda::Fase_Segunda()
{
	criaAlienigenas();
	criaPlataformas();
}

Fases::Fase_Segunda::~Fase_Segunda()
{
}

void Fases::Fase_Segunda::executar()
{
	//INSTANCIAR DINAMICAMENTE JOGADOR E COLOCAR EM LISTA
	jogador1.executar();
	pGerenteGrafico->printVida(jogador1.getNumVidas());
	pGerenteGrafico->printPont(jogador1.getPontuacao());
	LEnt.executarTodos();

	chao.executar();


	//fase1.Ger.verificaColisao(&jogador1, &fase1.esfera1);
	Ger.checaColisaoEsfera(&jogador1);
	Ger.colideCanto(&jogador1);
	Ger.checaColisaoObst(&jogador1);
	Ger.checaColisaoObst(&chao);
	Ger.checaColisaoIni(&jogador1);
	Ger.checaColisaoIni(&chao);
	Ger.verificaColisao(&jogador1, &chao);

	vector <Inimigo*>::iterator it;
	for (it = (Ger.getVecInimigos())->begin(); it != (Ger.getVecInimigos())->end(); it++)
	{
		if (Alienigena* a = dynamic_cast <Alienigena*>(*it))
		{
			//Ger.verificaColisao(&jogador1, );
		}
	}


	this->imprimir();
}

void Fases::Fase_Segunda::imprimir()
{
}

void Fases::Fase_Segunda::criaAlienigenas()
{
	int n = 1;
		//3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		Alienigena* a1 = new Alienigena(sf::Vector2f(500.f - 50.f * i, 200.f));
		Entidade* e1 = static_cast <Entidade*>(a1);
		LEnt.addEntidade(e1);
		Inimigo* i1 = static_cast <Inimigo*>(a1);
		Ger.getVecInimigos()->push_back(i1);
	}
}

void Fases::Fase_Segunda::criaPlataformas()
{
	int n = 3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		Plataforma* p1 = new Plataforma(sf::Vector2f(100.f - 300.f * i, -100.f + 100.f * i), sf::Vector2f(100.f + i * 100, 20.f));
		Entidade* e1 = static_cast <Entidade*>(p1);
		LEnt.addEntidade(e1);
		Ger.getListObst()->push_back(p1);
	}
}
