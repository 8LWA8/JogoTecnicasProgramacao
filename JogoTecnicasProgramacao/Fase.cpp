#include "Fase.h"

using namespace Personagens;

namespace Fases{

Fase::Fase(): pJogador1(nullptr), LEnt()
{
	criaEntidades();
}

Fase::~Fase()
{
	LEnt.limpaLista();
}

void Fase::criaEntidades()
{
	criaInimigos();
}

void Fase::criaInimigos()
{
	criaRobos();
}

void Fase::criaRobos()
{
	//sorteia quantos inimigos (entre 3 e 5)

	int n = 3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		//LEnt.LEs.incluaElemento(dynamic_cast <Entidade*>(new Robo));
		Robo* r1 = new Robo(sf::Vector2f(100.f + 150.f*i, 100.f));
		Entidade* e1 = static_cast <Entidade*>(r1);
		LEnt.addEntidade(e1);
		//cout << "a" << endl;
	}
}

void Fase::criaObstaculos()
{
}
}