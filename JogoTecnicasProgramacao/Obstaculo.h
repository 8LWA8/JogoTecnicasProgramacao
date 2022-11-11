#pragma once
#include "Entidade.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo :
            public Entidade
        {
        public:
            Obstaculo();
            ~Obstaculo();
            virtual void executar();
        };
    }
}
