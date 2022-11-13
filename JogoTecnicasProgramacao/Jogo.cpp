#include "Jogo.h"
#include "Fase_Primeira.h"

using namespace Fases;
using namespace Entidades::Personagens;

Jogo::Jogo(): 
jogador1(),
pGerenteGrafico(), fase1()
{
}

void Jogo::exec() 
{
	
	pGerenteGrafico = pGerenteGrafico->getInstance();

    while (pGerenteGrafico->isWindowOpen())
    {
        sf::Event event;
        while (pGerenteGrafico->getWindow()->pollEvent(event))
        {
			if (event.type == sf::Event::Closed)
				pGerenteGrafico->closeWindow();
        }
		
		
		pGerenteGrafico->clear();
		fase1.executar();
		execEnt();

		//TESTE
		Robo* rob = &fase1.robo1;
		Plataforma* plat = &fase1.chao;
		Ger.checkCollision(&jogador1, rob);
		Ger.checkCollision(&jogador1, plat);
		//TESTE

		
		
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
	jogador1.executar();
	//ini1.executar();
	fase1.espi1.executar();
	fase1.rocha1.executar();
	//fase1.robo1.executar();
	fase1.chao.executar();
}

/*Jogo::~Jogo() 
{
	pGerenteGrafico->~GerenteGrafico();
	jogador1.~Jogador();
}*/