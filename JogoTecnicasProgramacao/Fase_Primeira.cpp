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
	}

	void Fase_Primeira::imprimir()
	{
	}


	void Fase_Primeira::criaVilgax()
	{
		int n = 3 + rand() % 3;
		for (int i = 0; i < n; i++)
		{
			Vilgax* v1 = new Vilgax(sf::Vector2f(1000.f + 400.f * i, -200.f));
			Entidade* e1 = static_cast <Entidade*>(v1);
			LEnt.addEntidade(e1);
		}
	}

	void Fase_Primeira::criaEspinhos()
	{
		int n = 3 + rand() % 3;
		for (int i = 0; i < n; i++)
		{
			Espinhos* es1 = new Espinhos(sf::Vector2f(200.f + 300.f * i, 200.f));
			Entidade* e1 = static_cast <Entidade*>(es1);
			LEnt.addEntidade(e1);
		}
	}
}