#pragma once
#include "Entidade.h"

//using namespace Personagens;

namespace Entidades
{
	class Projetil :
		public Entidade
	{
	private:
		bool atingiu;
	public:
		Projetil(sf::Vector2f pos);
		~Projetil();
		void setAtingiu(bool a);
		bool getAtingiu();
		void executar();
		void danar(Entidade* ent);
	};
}

