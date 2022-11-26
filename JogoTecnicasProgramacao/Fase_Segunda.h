#pragma once
#include "Fase.h"
#include "Plataforma.h"
#include "Alienigena.h"
#include "MaquinaEstados.h"

using namespace Entidades;

namespace Fases
{
    class Fase_Segunda :
        public Fase
    {
    private:
    public:
        Fase_Segunda();
        ~Fase_Segunda();
        void executar();
        void imprimir();
        void criaPlataformas();
        void criaAlienigenas();
        void criaAlienigenas(float x, float y, bool estaVivo);
        
    };
}