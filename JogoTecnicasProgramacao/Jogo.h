#pragma once
//#include "Inimigo.h"
#include "Jogador.h"
#include "Fase_Primeira.h"
#include "Fase_Segunda.h"
#include "GerenteColisoes.h"

using namespace Entidades::Personagens;
using namespace Fases;

class Jogo
{
private:
	GerenteGrafico* pGerenteGrafico;
	GerenteColisoes Ger;
	Jogador jogador1;
	Inimigo ini1;
	Fase_Primeira fase1;
	Fase_Segunda fase2;

public:
	Jogo();

	void exec();
	void execEnt();
};

