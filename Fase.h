#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "Robo.h"
#include "ListaEntidades.h"


namespace Fases
{
    class Fase :
        public Ente
    {
	public:
		Listas::ListaEntidades LEnt;
	protected:
		Entidades::Personagens::Jogador* pJogador1;

		Entidades::Personagens::Inimigo* pInimigo1;
	public:
		Fase();
		~Fase();
		virtual void executar() = 0;
		void criaInimigos();
		void criaRobos();
		void criaObstaculos();

    };
}