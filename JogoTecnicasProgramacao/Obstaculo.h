#pragma once
#include "Entidade.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo :
            public Entidade
        {
        protected:
            bool causa_dano;
        public:
            Obstaculo();
            ~Obstaculo();
            virtual void executar();
        };
    }
}
