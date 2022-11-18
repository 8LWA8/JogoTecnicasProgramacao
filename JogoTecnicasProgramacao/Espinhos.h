#pragma once
#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Espinhos :
            public Obstaculo
        {
        private:
            float comprimento;
        public:
            Espinhos();
            Espinhos(const sf::Vector2f pos);
            ~Espinhos();
        };
    }
}
