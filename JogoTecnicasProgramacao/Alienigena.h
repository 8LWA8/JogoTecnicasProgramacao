#pragma once
#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        class Alienigena :
            public Inimigo
        {
        public:
            Alienigena();
            ~Alienigena();
            //void executar();
        };
    }
}
