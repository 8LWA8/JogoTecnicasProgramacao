#pragma once

#include "Estado.h"
#include <map>

//Código inspirado nos vídeos do monitor Matheus Augusto Burda (Burda Canal no youtube)
namespace Estados
{
	class MaquinaEstados
	{
    protected:
        IDestado IDatual;
        IDestado IDultimo;

        std::map<IDestado, Estado*> mapaEstados;

    public:
        MaquinaEstados();

        virtual ~MaquinaEstados();

        void mudaEstadoAtual(IDestado id);

        void updateEstadoAtual(const float dt);

        void renderEstadoAtual();

        IDestado getIDatual() const;

        void insereEstado(Estado* pEstado);

        IDestado getIDultimo() const;
	};
}