#include "Fase_Primeira.h"
#include <stdlib.h>
#include <time.h>

//#include <iostream>
//using namespace std;

namespace Fases {
	Fase_Primeira::Fase_Primeira() 
	{
		
		this->criaVilgax();
		this->criaEspinhos();
		this->criaPlataformas();
		this->criaJogadores();
		
		

	}

	Fases::Fase_Primeira::~Fase_Primeira()
	{
	}

	void Fases::Fase_Primeira::executar()
	{
		this->imprimir();

		
		
		
		LEnt.executarTodos();
		
		
		
		pGerenteGrafico->printVida(jogador1->getNumVidas());
		pGerenteGrafico->printPont(this->getPontTotal());
		
		Ger.gerenciarColisoes();
		
		
		/*
		//fase1.Ger.verificaColisao(&jogador1, &fase1.esfera1);
		Ger.checaColisaoEsfera(&jogador1);
		Ger.colideCanto(&jogador1);
		Ger.checaColisaoObst(&jogador1);
		Ger.checaColisaoObst(&chao);
		Ger.checaColisaoIni(&jogador1);
		Ger.checaColisaoIni(&chao);
		Ger.verificaColisao(&jogador1, &chao);
		

		*/
		
	}

	void Fase_Primeira::imprimir()
	{
		this->pGerenteGrafico->render(&corpo);
	}


	void Fase_Primeira::criaVilgax()
	{
		
		int n = 3 + rand() % 3;
		for (int i = 0; i < n; i++)
		{
			Vilgax* v1 = new Vilgax(sf::Vector2f(600.f - 100.f * i, -200.f));
			Entidade* e1 = static_cast <Entidade*>(v1);
			LEnt.addEntidade(e1);
			Inimigo* i1 = static_cast <Inimigo*>(v1);
			Ger.getVecInimigos()->push_back(i1);
		}
	}

	void Fase_Primeira::criaEspinhos()
	{
		int n = 3 + rand() % 3;
		for (int i = 0; i < n; i++)
		{
			Espinhos* es1 = new Espinhos(sf::Vector2f(100.f + 100.f * i, 0.f), sf::Vector2f(35.f, 25.f + 5*i), 25.f + 5 * i);
			Entidade* e1 = static_cast <Entidade*>(es1);
			LEnt.addEntidade(e1);
			//Obstaculo* o1 = static_cast <Obstaculo*>(es1);
			Ger.getListObst()->push_back(es1);
		}
	}

	void Fase_Primeira::criaPlataformas() 
	{
		Plataforma* plat = new Plataforma();
		LEnt.addEntidade(plat);
		Ger.getListObst()->push_back(plat);
	}
}