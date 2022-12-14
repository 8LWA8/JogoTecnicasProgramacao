#include "Fase_Segunda.h"

using namespace Fases;
#include <iostream>
Fases::Fase_Segunda::Fase_Segunda()
{
	if (Fase::getCarregar() == false)
	{
		this->criaAlienigenas();
		this->criaPlataformas();
	}
	else
	{
		this->pressed = false;
		float x;
		float y;
		bool estaVivo;
		float projx;
		float projy;
		bool projatingiu;
		bool projexiste;

		ifstream dados;

		dados.open("salvar/salvarAlien.txt", ios::out);

		while (!dados.eof())
		{
			/*dados >> id;*/
			dados >> x;
			dados >> y;
			dados >> estaVivo;
			dados >> projx;
			dados >> projy;
			dados >> projatingiu;
			dados >> projexiste;

			this->criaAlienigenas(x, y, estaVivo, projx, projy, projatingiu, projexiste);
		}

		dados.close();

		float tamx;
		float tamy;

		dados.open("salvar/salvarPlat.txt", ios::out);

		while (!dados.eof())
		{
			/*dados >> id;*/
			dados >> x;
			dados >> y;
			dados >> tamx;
			dados >> tamy;

			this->criaPlataformas(x, y, tamx, tamy);
		}

		dados.close();
	}

}

Fases::Fase_Segunda::~Fase_Segunda()
{
}

void Fases::Fase_Segunda::executar()
{
	//INSTANCIAR DINAMICAMENTE JOGADOR E COLOCAR EM LISTA
	this->imprimir();
	this->mostrarInfoFase();
	LEnt.executarTodos();
	Ger.gerenciarColisoes();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !pressed)
	{
		pressed = true;

		limpaTdsArq();

		LEnt.salvarTodos();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && !pressed)
	{
		pressed = true;

		MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::tela_pause);
	}

	float dt = relogio.getElapsedTime().asSeconds();
	if (dt >= 2.0f)
	{
		pressed = false;
		relogio.restart();
	}

	if (venceuFase() == true)
	{
		std::cout << "venceu!!!!" << std::endl;
		MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::tela_final);
		TelaFinal* estFinal = dynamic_cast<TelaFinal*>(MaquinaEstados::getMaquinaEstados()->getEstadoAtual());
		estFinal->setRank(this->getPontTotal());
	}
	
}

void Fases::Fase_Segunda::imprimir()
{
	this->pGerenteGrafico->render(this->getCorpo());
}

void Fases::Fase_Segunda::criaAlienigenas()
{
	int n = 3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		Alienigena* a1 = new Alienigena(sf::Vector2f(500.f - 50.f * i, 200.f));
		Entidade* e1 = static_cast <Entidade*>(a1);
		LEnt.addEntidade(e1);
		Inimigo* i1 = static_cast <Inimigo*>(a1);
		Ger.getVecInimigos()->push_back(i1);
	}
}

void Fases::Fase_Segunda::criaAlienigenas(float x, float y, bool estaVivo, float projx, float projy, bool projatingiu, bool projexiste)
{
	Alienigena* a1 = new Alienigena(sf::Vector2f(x, y));
	a1->setVivo(estaVivo);
	Entidade* e1 = static_cast <Entidade*>(a1);
	LEnt.addEntidade(e1);
	Inimigo* i1 = static_cast <Inimigo*>(a1);
	Ger.getVecInimigos()->push_back(i1);

	a1->getProj()->getCorpo()->setPosition(sf::Vector2f(projx, projy));
	a1->getProj()->setAtingiu(projatingiu);
	a1->getProj()->setExiste(projexiste);
}

void Fases::Fase_Segunda::criaPlataformas()
{
	Plataforma* plat = new Plataforma();
	LEnt.addEntidade(plat);
	Ger.getListObst()->push_back(plat);

	int n = 3 + rand() % 2;
	for (int i = 0; i < n; i++)
	{
		Plataforma* p1 = new Plataforma(sf::Vector2f(200.f - 400.f * i, -250.f + 100.f * i), sf::Vector2f(100.f + i * 100, 20.f));
		Entidade* e1 = static_cast <Entidade*>(p1);
		LEnt.addEntidade(e1);
		Ger.getListObst()->push_back(p1);

		EsferaPoder* esfera = new EsferaPoder(sf::Vector2f(p1->getCoord()->getX()+50.f, p1->getCoord()->getY() - 50.f));
		e1 = static_cast <Entidade*>(esfera);
		LEnt.addEntidade(e1);
		Ger.getVecPoder()->push_back(esfera);

		
	}
}

void Fases::Fase_Segunda::criaPlataformas(float x, float y, float tamx, float tamy)
{
	Plataforma* p1 = new Plataforma(sf::Vector2f(x, y), sf::Vector2f(tamx, tamy));
	Entidade* e1 = static_cast <Entidade*>(p1);
	LEnt.addEntidade(e1);
	Ger.getListObst()->push_back(p1);
}

