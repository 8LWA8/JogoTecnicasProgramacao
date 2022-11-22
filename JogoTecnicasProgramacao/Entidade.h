#pragma once
#include "Ente.h"
#include <fstream>

namespace Entidades
{ 
	class Entidade : public Ente
	{
	protected:
		Coord  coordenada;
		Coord tam;
		Coord vel;
		Coord coll;
		bool mov;

		float dano;
		
	public:
		Entidade();
		~Entidade();
		virtual void executar()=0;
		virtual void salvar() = 0;
		virtual void imprimir();
		void resetColl();
		void sofrer_gravidade();
		Coord* getCoord();  
		Coord* getTam();
		Coord* getVel();
		Coord* getColl();
		bool getMov() const;
		void setMov(bool m);

		void setDano(float dan);
		float getDano(); 
		virtual void danar(Entidade* ent) = 0;
		
	};
}
