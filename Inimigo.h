#pragma once
#include "Personagem.h"
#include <stdlib.h>

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo :
			public Personagem
		{
		private:
			sf::Clock relogio;  //Auxiliar para moverAleatorio
			short movAleatorio; //Auxiliar para moverAleatorio
		public:
			Inimigo();
			~Inimigo();
			virtual void executar();
			virtual void salvar() = 0;
			void moveAleatorio();
			void danar(Entidade* ent);
			void levarDano(float dano);
		};
	}
}