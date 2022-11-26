#pragma once
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		class Jogador2 : public Jogador
		{
		public:
			Jogador2();
			Jogador2(const sf::Vector2f pos);
			void mover();

		private:


		};


	}
}