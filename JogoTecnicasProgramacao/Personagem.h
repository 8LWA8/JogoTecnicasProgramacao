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
            void setVivo(bool v); 
            bool getVivo();
            virtual void executar();
            virtual void levaDano(Entidade* ent);
            virtual void danar(Entidade* ent); // <-- falta implementacao. O Jogador vai causar dano aos enemigos? o matar diretamente?
        };
    }
}