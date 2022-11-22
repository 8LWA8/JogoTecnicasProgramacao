#pragma once
#include "Entidade.h"
#include "Inimigo.h"
#include "Jogador1.h"
#include "Jogador2.h"
#include "EsferaPoder.h"
#include "Obstaculo.h"
#include "ListaEntidades.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <list>

using namespace Entidades;
using namespace Listas;
using namespace Personagens;
using namespace Obstaculos;
using namespace std;

namespace Gerenciadores {
	class GerenteColisoes
	{
		//ListaEntidades* pLista;
	private:
		vector <Inimigo*> LIs;
		list <Obstaculo*> LOs;
		vector <EsferaPoder*> LPs;
		vector <Jogador*> LJs;
		

	public:
		GerenteColisoes(/*ListaEntidades* pL*/);
		~GerenteColisoes();

		bool verificaColisao(Entidade* ent1, Entidade* ent2);
		bool colideEmbaixo(sf::FloatRect ent1Bounds, sf::FloatRect ent2Bounds);
		bool colideEmcima(sf::FloatRect ent1Bounds, sf::FloatRect ent2Bounds);
		bool colideDireita(sf::FloatRect ent1Bounds, sf::FloatRect ent2Bounds);
		bool colideEsquerda(sf::FloatRect ent1Bounds, sf::FloatRect ent2Bounds);

		vector <Inimigo*>* getVecInimigos();
		vector <EsferaPoder*>* getVecPoder();
		vector <Jogador*>* getVecJogs();
		list <Obstaculo*>* getListObst();

		void colideCanto(Entidade* ent);
		//void checaColisaoLista(Entidade* ent1);
		void checaColisaoObst(Entidade* ent);
		void checaColisaoIni(Entidade* ent);
		void checaColisaoEsfera(Jogador* jog);

		void gerenciarColisoes();

		void incluirJogador(Jogador* jog);
		void incluirObstaculo(Obstaculo* obst);
		void incluirInimigo(Inimigo* inim);
	};
}
