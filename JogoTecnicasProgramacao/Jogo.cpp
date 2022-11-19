#include "Jogo.h"
#include "Fase_Primeira.h"

using namespace Fases;
using namespace Entidades::Personagens;

#define WIDTH 1200

Jogo::Jogo(): 
jogador1(),
pGerenteGrafico(pGerenteGrafico->getInstance()), fase1()
{
	pGerenteGrafico->CenterView(0.0, 0.0);
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
		execEnt();

		

		
		
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
	Plataforma* plat = &fase1.chao;
	plat->getCorpo()->setSize(sf::Vector2f(WIDTH, 60.f));
	plat->getCorpo()->setPosition(sf::Vector2f(-WIDTH/2, 300.f));

	jogador1.executar();
	fase1.executar();
	fase1.chao.executar();
	
	fase1.Ger.verificaColisao(&jogador1, &fase1.esfera1);
	fase1.Ger.colideCanto(&jogador1);
	fase1.Ger.checaColisaoObst(&jogador1);
	fase1.Ger.checaColisaoObst(plat);
	fase1.Ger.checaColisaoIni(&jogador1);
	fase1.Ger.checaColisaoIni(plat);
	fase1.Ger.verificaColisao(&jogador1, plat);
	
}

/*Jogo::~Jogo() 
{
	pGerenteGrafico->~GerenteGrafico();
	jogador1.~Jogador();
}*/