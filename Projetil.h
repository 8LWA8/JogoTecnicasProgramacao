#pragma once
#include "Entidade.h"

namespace Entidades
{
	class Projetil :
		public Entidade
	{
	private:
		int dano;
	public:
		void setDano(int d);
		int getDano() const;
	};
}

