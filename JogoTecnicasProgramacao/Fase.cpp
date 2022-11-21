#include "Fase.h"
#include <vector>
#include <list>

using namespace Personagens;
using namespace Obstaculos;

namespace Fases{

	Fase::Fase() : jogador1(), LEnt(), Ger(/*&LEnt*/)
{
	criaRobos();
	criaRochas();
	criaPoderes();
}

Fase::~Fase()
{
	LEnt.limpaLista();
	Ger.getVecInimigos()->erase(Ger.getVecInimigos()->begin(), Ger.getVecInimigos()->end());
}


Plataforma Fase::getChao()
{
	return chao;
}

void Fase::criaRobos()
{
	//sorteia quantos inimigos (entre 3 e 5)

	int n = 3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		Robo* r1 = new Robo(sf::Vector2f(-600.f + 100.f*i, 100.f));
		Entidade* e1 = static_cast <Entidade*>(r1);
		LEnt.addEntidade(e1);
		Inimigo* i1 = static_cast <Inimigo*>(r1);
		Ger.getVecInimigos()->push_back(i1);
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
		Ger.getListObst()->push_back(o1);
	}
}

void Fase::criaPoderes()
{
	int n = 3 + rand() % 4;
	for (int i = 0; i < n; i++)
	{
		EsferaPoder* esfera = new EsferaPoder(sf::Vector2f(-550.f + 150.f * i, 150.f));
		Entidade* e1 = static_cast <Entidade*>(esfera);
		LEnt.addEntidade(e1);
		Ger.getVecPoder()->push_back(esfera);
	}
}

}