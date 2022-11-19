#include "Fase.h"
#include <vector>
#include <list>

using namespace Personagens;
using namespace Obstaculos;

namespace Fases{

	Fase::Fase() : pJogador1(nullptr), LEnt(), Ger(/*&LEnt*/)
{
	criaRobos();
	criaRochas();
	criaPoderes();
}

Fase::~Fase()
{
	LEnt.limpaLista();
	Ger.LIs.erase(Ger.LIs.begin(), Ger.LIs.end());
}


void Fase::criaRobos()
{
	//sorteia quantos inimigos (entre 3 e 5)

	int n = 3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		Robo* r1 = new Robo(sf::Vector2f(-600.f + 150.f*i, 100.f));
		Entidade* e1 = static_cast <Entidade*>(r1);
		LEnt.addEntidade(e1);
		Inimigo* i1 = static_cast <Inimigo*>(r1);
		Ger.LIs.push_back(i1);
	}
}

void Fase::criaRochas()
{
	int n = 3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		Rocha* r1 = new Rocha(sf::Vector2f(-600.f + 100.f * i, 0.f));
		Entidade* e1 = static_cast <Entidade*>(r1);
		LEnt.addEntidade(e1);
		Obstaculo* o1 = static_cast <Obstaculo*>(r1);
		Ger.LOs.push_back(o1);
	}
}

void Fase::criaPoderes()
{
	int n = 2 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		EsferaPoder* esfera = new EsferaPoder(sf::Vector2f(-550.f + 150.f * i, 150.f));
		Entidade* e1 = static_cast <Entidade*>(esfera);
		LEnt.addEntidade(e1);
		Ger.LPs.push_back(esfera);
	}
}

}