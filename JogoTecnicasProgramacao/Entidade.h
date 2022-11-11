#pragma once
#include "Ente.h"


namespace Entidades
{ 
	class Entidade : public Ente
	{
	protected:
		Coord  coordenada;
		Coord tam;
		
	public:
		Entidade();
		~Entidade();
		virtual void executar()=0;
		virtual void imprimir();
		Coord* getCoord();  //const???
		Coord* getTam();

	};
}
