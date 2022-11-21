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
            float altura;
        public:
            Espinhos();
            Espinhos(const sf::Vector2f pos, const sf::Vector2f tam, float altu);
            ~Espinhos();
            void setAltura(float l);
            float getAltura();
            void danar(Entidade* ent);
        };
    }
}
