#pragma once
#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        class Robo :
            public Inimigo
        {
        private:
            bool persegue;
        public:
            Robo();
            Robo(const sf::Vector2f pos);
            ~Robo();
            virtual std::string salvar();
            void setPersegue(bool per);
            bool getPersegue();
            //void executar();
        };

    }
}
