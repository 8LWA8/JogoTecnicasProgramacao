#pragma once
#include "IDs.h"
#include "Fase.h"
#include "Fase_Primeira.h"
#include "Fase_Segunda.h"

using namespace Fases;

namespace Construtor
{
	class ConstrutorFase
	{
    public:
        ConstrutorFase();
        ~ConstrutorFase();
        Fase* criarFase(const IDs::IDs ID);
    private:
        Fase* criarFase1();
        Fase* criarFase2();
    };
}