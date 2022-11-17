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
            bool vivo;
        public:
            Personagem();
            ~Personagem();
            void setVivo(bool v); 
            bool getVivo();
            virtual void executar();
        };
    }
}