#pragma once

#include "Estado.h"
#include "GerenteGrafico.h"
#include "Fase_Primeira.h"
#include "Fase_Segunda.h"
#include "Menu.h"
#include "TelaFinal.h"
#include "TelaRanking.h"
#include "TelaPause.h"
#include "IDs.h"
#include <stack>
#include <fstream>

//Código inspirado nos vídeos do monitor Giovane (Gege++ no youtube) e no seu Github (https://github.com/Giovanenero/JogoPlataforma2D-Jungle)
namespace Estados
{
	class MaquinaEstados
	{
    private:

        std::stack<Estado*> pilhaEstados;

        //Singleton
        static MaquinaEstados* pMaquinaEstados;
        MaquinaEstados();

    public:
        ~MaquinaEstados();

        static MaquinaEstados* getMaquinaEstados();
        static void deleteInstance();

        void executar();

        void addEstado(const IDs::IDs ID);

        void removerEstado();

        Estado* getEstadoAtual();
	};
}