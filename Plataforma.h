#pragma once
#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma :
            public Obstaculo
        {
        private:
            bool flutua;
        public:
            Plataforma();
            Plataforma(const sf::Vector2f pos, const sf::Vector2f tamanho);
            ~Plataforma();
            void executar();
            void anularGravidade();
            void setFlutua(bool f);
            bool getFlutua();
            void salvar();
        };
    }
}
