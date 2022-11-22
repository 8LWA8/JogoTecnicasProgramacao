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
		bool existe;
		sf::Vector2f posAlien;
	public:
		Projetil(sf::Vector2f pos);
		~Projetil();
		void setAtingiu(bool a);
		bool getAtingiu();
		void executar();
		void setExiste(bool e);
		bool getExiste();
		void danar(Entidade* ent);
		void recebePosAlien(sf::Vector2f posAli);
		

		//VIRTUAL PURA TESTE
		void salvar();
	};
}

