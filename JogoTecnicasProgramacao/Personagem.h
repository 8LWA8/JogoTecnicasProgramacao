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
            float num_vidas;
            bool vivo;
        public:
            Personagem();
            ~Personagem();
            float getNumVidas();
            void setNumVidas(float vidas);
            void setVivo(bool v); 
            bool getVivo();
            virtual void executar();
            virtual void danar(Entidade* ent);
            virtual void levarDano(float dano) = 0;
        };
    }
}