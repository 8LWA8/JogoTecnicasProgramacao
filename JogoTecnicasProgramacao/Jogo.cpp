#include "Jogo.h"
#include "Fase_Primeira.h"

using namespace Fases;
using namespace Entidades::Personagens;

#define WIDTH 1200

Jogo::Jogo(): 
pGerenteGrafico(pGerenteGrafico->getInstance())
{
	MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::jogar_fase2);
	pGerenteGrafico->CenterView(0.0, 0.0);
	
}

void Jogo::exec() 
{
	//TESTE ---------------------------------------------------------------
	Estado* est = MaquinaEstados::getMaquinaEstados()->getEstadoAtual();

	Fase_Primeira* fas = dynamic_cast<Fase_Primeira*>(est);
	//fas->getJog1()->recuperar();	
	//TESTE ---------------------------------------------------------------

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
		
		
		
    }

	
	//fas->getJog1()->salvar();


    int i = 0;


	
}

Jogo::~Jogo() 
{
	pGerenteGrafico->deleteInstance();
}