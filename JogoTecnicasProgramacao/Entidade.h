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
		bool mov_dir;
		bool mov_esq;
		
	public:
		Entidade();
		~Entidade();
		virtual void executar()=0;
		virtual void imprimir();
		void resetColl();
		Coord* getCoord();  
		Coord* getTam();
		Coord* getVel();
		Coord* getColl();
		bool getMov() const;
		void setMov(bool m);
		void setMovDir(bool m);
		void setMovEsq(bool m);
	};
}
