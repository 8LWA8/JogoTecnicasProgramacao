#pragma once
#include "Fase.h"
#include "Lista.h"
#include "ListaEntidades.h"
#include "Lista.h"
#include "Inimigo.h"
#include "Robo.h"
#include "Rocha.h"
#include "Alienigena.h"
#include "Plataforma.h"
#include "Espinhos.h"
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

namespace Fases
{
    class Fase_Primeira :
        public Fase
    {
    private:
    public:
        Fase_Primeira();
        ~Fase_Primeira();
        Robo robo1;
        Alienigena alien1;
        Rocha rocha1;
        Espinhos espi1;
        Plataforma chao;

        void executar();
        void imprimir();
    };
}