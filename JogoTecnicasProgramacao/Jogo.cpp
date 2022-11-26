#include "Jogo.h"
#include "Fase_Primeira.h"

using namespace Fases;
using namespace Entidades::Personagens;

#define WIDTH 1200

Jogo::Jogo(): 
pGerenteGrafico(pGerenteGrafico->getInstance())
{
	MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::menu);
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


			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					playerInput += event.text.unicode;
					playerText.setString(playerInput);


				}
				pGerenteGrafico->getWindow()->draw(playerText);
			}

		}

		pGerenteGrafico->clear();
		MaquinaEstados::getMaquinaEstados()->executar();
		pGerenteGrafico->display();
	}

}


	
	


	


Jogo::~Jogo() 
{
	pGerenteGrafico->deleteInstance();
}