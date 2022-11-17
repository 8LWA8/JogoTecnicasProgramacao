#include "Fase.h"

using namespace Personagens;
using namespace Obstaculos;

namespace Fases{

Fase::Fase(): pJogador1(nullptr), LEnt()
{
	criaRobos();
	criaRochas();
}

Fase::~Fase()
{
	LEnt.limpaLista();
}


void Fase::criaRobos()
{
	//sorteia quantos inimigos (entre 3 e 5)

	int n = 3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		Robo* r1 = new Robo(sf::Vector2f(-400.f + 150.f*i, 100.f));
		Entidade* e1 = static_cast <Entidade*>(r1);
		LEnt.addEntidade(e1);
	}
}

void Fase::criaRochas()
{
	int n = 3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		Rocha* r1 = new Rocha(sf::Vector2f(-900.f + 300.f * i, 0.f));
		Entidade* e1 = static_cast <Entidade*>(r1);
		LEnt.addEntidade(e1);
	}
}

}