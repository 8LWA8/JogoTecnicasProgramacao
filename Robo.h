#pragma once
#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        class Robo :
            public Inimigo
        {
        public:
            Robo();
            ~Robo();
            //void executar();
        };

    }
}
