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
            virtual void danar(Entidade* ent);
            virtual const bool getCausa_dano();
        };
    }
}
