#pragma once
#include "Entidade.h"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem :
            public Entidade
        {
        protected:
            int num_vidas;
        public:
            Personagem();
            ~Personagem();
            virtual void executar();
        };
    }
}