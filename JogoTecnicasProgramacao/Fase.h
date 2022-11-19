#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "Robo.h"
#include "Rocha.h"
#include "EsferaPoder.h"
#include "Entidade.h"
#include "ListaEntidades.h"
#include "GerenteColisoes.h"



namespace Fases
{
    class Fase :
        public Ente
    {
	public:
		Listas::ListaEntidades LEnt;
		Gerenciadores::GerenteColisoes Ger;
		EsferaPoder esfera1;
	protected:
		Entidades::Personagens::Jogador* pJogador1;

		//Entidades::Personagens::Inimigo* pInimigo1;
	public:
		Fase();
		~Fase();
		virtual void executar() = 0;
		void criaRobos();
		void criaRochas();
		void criaPoderes();
    };
}