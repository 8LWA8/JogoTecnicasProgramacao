#pragma once
//#include "Inimigo.h"

#include "Jogador.h"
#include "IDs.h"
#include "Fase_Primeira.h"
#include "Fase_Segunda.h"
#include "EsferaPoder.h"
#include "GerenteColisoes.h"
#include "MaquinaEstados.h"

using namespace Entidades::Personagens;
using namespace Fases;

class Jogo
{
private:
	GerenteGrafico* pGerenteGrafico;
	MaquinaEstados* pMaquinaEst;

public:
	Jogo();
	~Jogo();
	void exec();
};

