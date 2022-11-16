#pragma once
#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        class Alienigena :
            public Inimigo
        {
        private:
            bool atirou;
        public:
            Alienigena();
            ~Alienigena();
            //void executar();
            void setAtirou(bool estado);
            bool getAtirou();
        };
    }
}
 