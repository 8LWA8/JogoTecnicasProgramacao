#pragma once
#include "Inimigo.h"
namespace Entidades
{
    namespace Personagens
    {
        class Vilgax :
            public Inimigo
        {
        protected:
            int poder_dano;
        public:
            Vilgax();
            Vilgax(const sf::Vector2f pos);
            ~Vilgax();

            void setPoderDano(int d);
            int getPoderDano();

        };
    }
}