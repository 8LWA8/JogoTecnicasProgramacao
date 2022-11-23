#include "Fase_Segunda.h"

using namespace Fases;
#include <iostream>
Fases::Fase_Segunda::Fase_Segunda()
{
	this->criaAlienigenas();
	this->criaPlataformas();
	this->criaJogadores();
}

Fases::Fase_Segunda::~Fase_Segunda()
{
}

void Fases::Fase_Segunda::executar()
{
	//INSTANCIAR DINAMICAMENTE JOGADOR E COLOCAR EM LISTA
	this->imprimir();
	pGerenteGrafico->printVida(jogador1->getNumVidas());
	pGerenteGrafico->printPont(this->getPontTotal());
	LEnt.executarTodos();

	Ger.gerenciarColisoes();

	/*
	vector <Inimigo*>::iterator it;
	for (it = (Ger.getVecInimigos())->begin(); it != (Ger.getVecInimigos())->end(); it++)
	{
		if (Alienigena* a = dynamic_cast <Alienigena*>(*it))
		{
			Ger.colideCanto(a->getProj());
			if (a->getProj()->getExiste() == true)
			{
				if (Ger.verificaColisao(jogador1, a->getProj()))
				{
					
					a->getProj()->danar(jogador1);
					a->getProj()->setAtingiu(true);
				}
			}
		}
	}*/


	
}

void Fases::Fase_Segunda::imprimir()
{
	this->pGerenteGrafico->render(this->getCorpo());
}

void Fases::Fase_Segunda::criaAlienigenas()
{
	int n = 3 + rand() % 3;
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
	Plataforma* plat = new Plataforma();
	LEnt.addEntidade(plat);
	Ger.getListObst()->push_back(plat);

	int n = 3 + rand() % 2;
	for (int i = 0; i < n; i++)
	{
		Plataforma* p1 = new Plataforma(sf::Vector2f(200.f - 300.f * i, -250.f + 100.f * i), sf::Vector2f(100.f + i * 100, 20.f));
		Entidade* e1 = static_cast <Entidade*>(p1);
		LEnt.addEntidade(e1);
		Ger.getListObst()->push_back(p1);
	}
}

