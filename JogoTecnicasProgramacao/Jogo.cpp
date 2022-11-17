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
	plat->getCorpo()->setSize(sf::Vector2f(4000.f, 110.f));
	plat->getCorpo()->setPosition(sf::Vector2f(-1000.f, 300.f));
	//fase1.alien1.executar();
	jogador1.executar();
	fase1.executar();
	fase1.chao.executar();
	//TESTE
	
	Ger.checaColisaoLista(&jogador1, &fase1.LEnt);
	Ger.checaColisaoLista(plat, &fase1.LEnt);
	//std::cout << "jogador - plat" << std::endl;
	//Ger.checkCollision(&jogador1, plat);
	Ger.verificaColisao(&jogador1, plat, &fase1.LEnt);
	//std::cout << "alien - plat" << std::endl;
	//Ger.checkCollision(&(fase1.alien1), plat);
	//std::cout << "jogador - alien" << std::endl;
	//Ger.checkCollision(&jogador1, &fase1.alien1);
	//Ger.verificaColisao(&jogador1, &fase1.alien1);
	//TESTE
	
}

/*Jogo::~Jogo() 
{
	pGerenteGrafico->~GerenteGrafico();
	jogador1.~Jogador();
}*/