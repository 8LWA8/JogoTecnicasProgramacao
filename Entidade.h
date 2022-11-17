#pragma once
#include "Ente.h"


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
		
	public:
		Entidade();
		~Entidade();
		virtual void executar()=0;
		virtual void imprimir();
		void resetColl();
		void sofrer_gravidade();
		Coord* getCoord();  
		Coord* getTam();
		Coord* getVel();
		Coord* getColl();
		bool getMov() const;
		void setMov(bool m);
	};
}
