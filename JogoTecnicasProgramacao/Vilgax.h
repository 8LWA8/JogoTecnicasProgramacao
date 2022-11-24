#pragma once
#include "Inimigo.h"
namespace Entidades
{
    namespace Personagens
    {
        class Vilgax :
            public Inimigo
        {
        private:
            float poder_dano;
        public:
            Vilgax();
            Vilgax(const sf::Vector2f pos);
            ~Vilgax();

            virtual std::string salvar();
            void setPoderDano(float d);
            float getPoderDano();

        };
    }
}