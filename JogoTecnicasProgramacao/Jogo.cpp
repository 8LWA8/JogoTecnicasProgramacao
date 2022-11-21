#include "Jogo.h"
#include "Fase_Primeira.h"

using namespace Fases;
using namespace Entidades::Personagens;

#define WIDTH 1200

Jogo::Jogo(): 
pGerenteGrafico(pGerenteGrafico->getInstance()), fase1()
{
	MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::jogar_fase1);
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
        }
		
		
		pGerenteGrafico->clear();

		MaquinaEstados::getMaquinaEstados()->executar();
		//execEnt();
		
		
		
		
		//fase1.ini1.imprimir();
		pGerenteGrafico->display();
		
		
		
		
		//window.clear();
        //jogador1.desenhar();
        //ini1.desenhar();
        //window.display();
    }
}

void Jogo::execEnt()
{
	/*Plataforma plat = fase1.getChao();
	plat.getCorpo()->setSize(sf::Vector2f(WIDTH, 60.f));*/

	
	fase1.executar();
	//fase2.executar();
	
}

Jogo::~Jogo() 
{
	pGerenteGrafico->deleteInstance();
}