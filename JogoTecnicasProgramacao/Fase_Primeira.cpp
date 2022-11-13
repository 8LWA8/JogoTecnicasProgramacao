#include "Fase_Primeira.h"
#include <stdlib.h>
#include <time.h>

//#include <iostream>
//using namespace std;

namespace Fases {
	Fase_Primeira::Fase_Primeira()
	{
		

	}

	Fases::Fase_Primeira::~Fase_Primeira()
	{
	}

	void Fases::Fase_Primeira::executar()
	{
		//cout << "fase1 exe" << endl;
		LEnt.executarTodos();
	}

	void Fases::Fase_Primeira::imprimir()
	{
	}
}