#pragma once
#include "Entidade.h"

namespace Entidades
{
	class Projetil :
		public Entidade
	{
	private:
		bool atingiu;
	public:
		Projetil();
		~Projetil();
		void setAtingiu(bool a);
		bool getAtingiu();
		void executar();
		void danar(Entidade* ent);
	};
}

