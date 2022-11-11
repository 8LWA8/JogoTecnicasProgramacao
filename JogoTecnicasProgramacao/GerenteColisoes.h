#pragma once
#include "Entidade.h"
#include <math.h>

using namespace Entidades;
namespace Gerenciadores {
	class GerenteColisoes
	{
	private:



	public:
		GerenteColisoes();
		~GerenteColisoes();

		void checkCollision(Entidade* ent1, Entidade* ent2);

	};
}
