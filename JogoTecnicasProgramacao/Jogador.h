#pragma once
#include "Personagem.h"
#include <string>
//#include <SFML/Graphics.hpp>
using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        class Jogador :
            public Personagem
        {
        private:
            int pontuacao;
        public:
            Jogador();
            ~Jogador();
            void executar();
            void mover();
            void setPontuacao(int p);
            int getPontuacao();
        };
    }
}