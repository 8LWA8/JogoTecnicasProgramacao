#pragma once
#include "Personagem.h"



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
            virtual ~Jogador();
            void executar();
            virtual void mover() = 0;
            void setPontuacao(int p);
            int getPontuacao();
            void ficarEmpoderado();
            bool getEmpoderado();
            void levarDano(float dano);
            void salvar();
            
            void operator++(int);

        };
    }
}