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
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace Estados;

namespace Fases
{
    class Fase :
        public Estado
    {
	private:
		static int num_jog;
		static bool carregar;
	protected:
		Jogador1* jogador1;
		Jogador2* jogador2;
		sf::Clock relogio;
		bool pressed;
		Gerenciadores::GerenteColisoes Ger;
		Listas::ListaEntidades LEnt;
		int pontTotal;
		void limpaTdsArq();

		//Entidades::Personagens::Inimigo* pInimigo1;
	public:
		Fase();
		~Fase();
		virtual void executar() = 0;
		virtual void imprimir()= 0;
		void criaRobos();
		void criaRobos(float x, float y, bool estaVivo);
		void criaRochas();
		void criaRochas(float x, float y);
		void criaPoderes();
		void criaPoderes(float x, float y, bool colec);
		virtual void criaPlataformas() = 0;
		void criaJogadores();
		void criaJogadores(float x, float y, bool empoder, float n_vidas, int pont, bool estaVivo);
		void criaJogadores(float x, float y, bool empoder, float n_vidas, int pont, bool estaVivo, float x2, float y2, bool empoder2, float n_vidas2, int pont2, bool estaVivo2);
		Jogador1* getJog1();
		Jogador2* getJog2();
		int getPontTotal();
		void setPontTotal(int p);
		void mostrarInfoFase();
		bool venceuFase();
		static void setNumJog(int n);
		static int getNumJog();
		static bool getCarregar();
		static void setCarregar(bool c);
    };
	
}