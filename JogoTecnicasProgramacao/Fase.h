#pragma once
#include "Jogador1.h"
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
	protected:
		Jogador1 jogador1;
		Gerenciadores::GerenteColisoes Ger;
		Listas::ListaEntidades LEnt;
		EsferaPoder esfera1;
		
	
	

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