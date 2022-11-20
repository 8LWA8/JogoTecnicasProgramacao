#include "Fase_Primeira.h"
#include <stdlib.h>
#include <time.h>

//#include <iostream>
//using namespace std;

namespace Fases {
	Fase_Primeira::Fase_Primeira()
	{
		criaVilgax();
		criaEspinhos();

	}

	Fases::Fase_Primeira::~Fase_Primeira()
	{
	}

	void Fases::Fase_Primeira::executar()
	{
		//cout << "fase1 exe" << endl;

		
		LEnt.executarTodos();

		
		
		//this->imprimir();
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
			Ger.LIs.push_back(i1);
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
			Ger.LOs.push_back(es1);
		}
	}
}