#include "Jogo.h"
#include "Fase_Primeira.h"

using namespace Fases;
using namespace Entidades::Personagens;

#define WIDTH 1200

Jogo::Jogo() :
	pGerenteGrafico(pGerenteGrafico->getInstance()), pMaquinaEst(pMaquinaEst->getMaquinaEstados())
{
	pMaquinaEst->addEstado(IDs::IDs::menu);
	pGerenteGrafico->CenterView(0.0, 0.0);

}

void Jogo::exec()
{


	while (pGerenteGrafico->isWindowOpen())
	{
		sf::Event event;
		while (pGerenteGrafico->getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				pGerenteGrafico->closeWindow();

			sf::String playerInput;
			sf::Text playerText;
			playerText.setPosition(60, 300);
		}

		pGerenteGrafico->clear();
		pMaquinaEst->executar();
		pGerenteGrafico->display();
	}

}


Jogo::~Jogo() 
{
	pGerenteGrafico->deleteInstance();
	pMaquinaEst->deleteInstance();
}