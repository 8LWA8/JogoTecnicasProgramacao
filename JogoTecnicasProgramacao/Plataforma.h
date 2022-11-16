#pragma once
#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma :
            public Obstaculo
        {
        protected:
            bool flutua;
        public:
            Plataforma();
            ~Plataforma();
            void executar();
            void setFlutua(bool f);
            bool getFlutua();
        };
    }
}
