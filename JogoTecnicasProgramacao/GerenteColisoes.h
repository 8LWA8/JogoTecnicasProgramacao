#pragma once
#include "Entidade.h"
#include <math.h>
#include <iostream>

using namespace Entidades;
namespace Gerenciadores {
	class GerenteColisoes
	{
	private:



	public:
		GerenteColisoes();
		~GerenteColisoes();

		void verificaColisaoHor(Entidade* ent1, Entidade* ent2);
		void checkCollision(Entidade* ent1, Entidade* ent2);
		void checkGround(Entidade* ent1, Entidade* plat);

	};
}
