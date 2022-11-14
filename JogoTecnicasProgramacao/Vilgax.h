#pragma once
#include "Inimigo.h"
namespace Entidades
{
    namespace Personagens
    {
        class Vilgax :
            public Inimigo
        {
        public:
            Vilgax();
            Vilgax(const sf::Vector2f pos);
            ~Vilgax();
        };
    }
}