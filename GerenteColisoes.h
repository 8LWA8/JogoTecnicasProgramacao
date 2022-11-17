#pragma once
#include "Entidade.h"
#include "ListaEntidades.h"
#include <math.h>
#include <iostream>

using namespace Entidades;
using namespace Listas;

namespace Gerenciadores {
	class GerenteColisoes
	{
	private:



	public:
		GerenteColisoes();
		~GerenteColisoes();

		void verificaColisao(Entidade* ent1, Entidade* ent2, ListaEntidades* lista);
		void checkCollision(Entidade* ent1, Entidade* ent2);
		void checaColisaoLista(Entidade* ent1, ListaEntidades* lista);
		//void checkGround(Entidade* ent1, Entidade* plat);

	};
}
