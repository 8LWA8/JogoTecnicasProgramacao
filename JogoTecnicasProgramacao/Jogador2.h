#pragma once
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		class Jogador2 : public Jogador
		{
		public:
			Jogador2();
			void mover();
			Jogador2 operator++(int);

		private:


		};


	}
}