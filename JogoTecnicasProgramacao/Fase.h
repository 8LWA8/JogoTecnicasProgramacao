#pragma once
#include "Jogador1.h"
#include "Jogador2.h"
#include "Inimigo.h"
#include "Robo.h"
#include "Estado.h"
#include "Plataforma.h"
#include "Rocha.h"
#include "EsferaPoder.h"
#include "Entidade.h"
#include "ListaEntidades.h"
#include "GerenteColisoes.h"

using namespace Estados;

namespace Fases
{
    class Fase :
        public Estado
    {
	protected:
		 Jogador1* jogador1;
		 Jogador2* jogador2;
		Gerenciadores::GerenteColisoes Ger;
		Listas::ListaEntidades LEnt;
	

		//Entidades::Personagens::Inimigo* pInimigo1;
	public:
		Fase();
		~Fase();
		virtual void executar() = 0;
		virtual void imprimir()= 0;
		void criaRobos();
		void criaRochas();
		void criaPoderes();
		virtual void criaPlataformas() = 0;
		virtual void criaJogadores();
		Jogador1* getJog1();
		Jogador2* getJog2();
    };
	
}