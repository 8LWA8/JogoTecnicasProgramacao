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
            bool empoderado;
            sf::Clock relogio; //auxiliar para contar o tempo
        public:
            Jogador();
            ~Jogador();
            void executar();
            void mover();
            void setPontuacao(int p);
            int getPontuacao();
            void ficarEmpoderado();
            bool getEmpoderado();
            void levarDano(float dano);

        };
    }
}