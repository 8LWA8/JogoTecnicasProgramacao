#pragma once
#include "Jogador.h"
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
		Jogador jogador1;
		Gerenciadores::GerenteColisoes Ger;
		Listas::ListaEntidades LEnt;
		Plataforma chao;
	
	

		//Entidades::Personagens::Inimigo* pInimigo1;
	public:
		Fase();
		~Fase();
		virtual void executar() = 0;
		Plataforma getChao();
		void criaRobos();
		void criaRochas();
		void criaPoderes();
    };
}