#pragma once
#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        class Robo :
            public Inimigo
        {
        private:
        public:
            Robo();
            Robo(const sf::Vector2f pos);
            ~Robo();
            void salvar();
        };

    }
}
