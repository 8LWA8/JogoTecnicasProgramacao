#pragma once
#include "Inimigo.h"
#include "Projetil.h"

namespace Entidades
{
    namespace Personagens
    {
        class Alienigena :
            public Inimigo
        {
        private:
            bool atirou;
            Projetil* proj;
        public:
            Alienigena(const sf::Vector2f pos);
            ~Alienigena();
            void executar();
            void atirar();
            void setAtirou(bool estado);
            void getProj();
            bool getAtirou();
        };
    }
}
 