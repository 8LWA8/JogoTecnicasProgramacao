#pragma once
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		class Jogador1 : public Jogador
		{

		private:

		public:
			Jogador1();
			Jogador1(const sf::Vector2f pos);
			void mover();
			
		};


	}
}