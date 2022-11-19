#pragma once
#include "Obstaculo.h"
#include "Personagem.h"
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
            Espinhos(const sf::Vector2f pos, const sf::Vector2f tam, float comp);
            ~Espinhos();
            const bool getCausa_dano();
            void danar(Entidade* ent);
        };
    }
}
