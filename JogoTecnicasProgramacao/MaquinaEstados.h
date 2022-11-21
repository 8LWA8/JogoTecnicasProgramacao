#pragma once

#include "Estado.h"
#include "GerenteGrafico.h"
#include "Fase_Primeira.h"
#include "Fase_Segunda.h"
#include "Menu.h"
#include "IDs.h"
#include <stack>

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

        void executar();

        void addEstado(const IDs::IDs ID);

        void removerEstado();

        Estado* getEstadoAtual();
	};
}