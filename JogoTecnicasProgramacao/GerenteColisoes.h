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

		ListaEntidades* pLista;

	public:
		GerenteColisoes(ListaEntidades* pL);
		~GerenteColisoes();

		void verificaColisao(Entidade* ent1, Entidade* ent2);
		bool colideEmbaixo(sf::FloatRect ent1Bounds, sf::FloatRect ent2Bounds);
		bool colideEmcima(sf::FloatRect ent1Bounds, sf::FloatRect ent2Bounds);
		bool colideDireita(sf::FloatRect ent1Bounds, sf::FloatRect ent2Bounds);
		bool colideEsquerda(sf::FloatRect ent1Bounds, sf::FloatRect ent2Bounds);
		//void checkCollision(Entidade* ent1, Entidade* ent2);
		void checaColisaoLista(Entidade* ent1);
		//void checkGround(Entidade* ent1, Entidade* plat);

	};
}
