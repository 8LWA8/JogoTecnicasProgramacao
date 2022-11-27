#include "Fase_Primeira.h"
#include <stdlib.h>
#include <time.h>


//#include <iostream>
//using namespace std;

namespace Fases {
	Fase_Primeira::Fase_Primeira()
	{
		this->criaPlataformas();
		if (Fase::getCarregar() == false)
		{
			this->pressed = false;
			this->criaVilgax();
			this->criaEspinhos();
			//this->criaJogadores();
		}
		else
		{
			this->pressed = false;
			/*int id;*/
			float x;
			float y;
			bool estaVivo;

			ifstream dados;

			dados.open("salvar/salvarVilgax.txt", ios::out);

			while (!dados.eof())
			{
				/*dados >> id;*/
				dados >> x;
				dados >> y;
				dados >> estaVivo;

				this->criaVilgax(x, y, estaVivo);
			}

			dados.close();

			float altu;
			float tamX;
			float tamY;
			
			dados.open("salvar/salvarEspi.txt", ios::out);

			while (!dados.eof())
			{
				/*dados >> id;*/
				dados >> x;
				dados >> y;
				dados >> tamX;
				dados >> tamY;
				dados >> altu;

				this->criaEspinhos(x, y, tamX, tamY, altu);
			}

			dados.close();

			//this->criaJogadores();
		}

	}

	Fases::Fase_Primeira::~Fase_Primeira()
	{
		
	}

	void Fases::Fase_Primeira::executar()
	{
		this->imprimir();


		if (jogador2 == nullptr && jogador1->getVivo()==false)
		{
			MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::tela_final);
		}
		else if (jogador2 != nullptr && jogador1->getVivo() == false && jogador2->getVivo() == false)
		{
			MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::tela_final);
		}
		
		
		LEnt.executarTodos();
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !pressed)
		{
			pressed = true;

			limpaTdsArq();

			LEnt.salvarTodos();
		}

		float dt = relogio.getElapsedTime().asSeconds();
		if (dt >= 2.0f)
		{
			pressed = false;
			relogio.restart();
		}
		
		this->mostrarInfoFase();
		
		Ger.gerenciarColisoes();
		
		
		if (venceuFase() == true)
		{
			std::cout << "venceu!!!!" << std::endl;
			MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::jogar_fase2);
			Estado* est = MaquinaEstados::getMaquinaEstados()->getEstadoAtual();
			Fase_Segunda* fas2 = dynamic_cast<Fase_Segunda*>(est);
			if (fas2->getJog1() != NULL && fas2->getJog2() != NULL) {
				fas2->getJog1()->setPontuacao(this->getJog1()->getPontuacao());
				fas2->getJog2()->setPontuacao(this->getJog2()->getPontuacao());
			}
			else if (fas2->getJog1() != NULL) 
			{
				fas2->getJog1()->setPontuacao(this->getJog1()->getPontuacao());
			}
			


		}	
	}

	void Fase_Primeira::imprimir()
	{
		this->pGerenteGrafico->render(&corpo);
	}


	void Fase_Primeira::criaVilgax()
	{
		
		int n = 3 + rand() % 3;
		for (int i = 0; i < n; i++)
		{
			Vilgax* v1 = new Vilgax(sf::Vector2f(600.f - 100.f * i, -200.f));
			Entidade* e1 = static_cast <Entidade*>(v1);
			LEnt.addEntidade(e1);
			Inimigo* i1 = static_cast <Inimigo*>(v1);
			Ger.getVecInimigos()->push_back(i1);
		}
	}

	void Fase_Primeira::criaVilgax(float x, float y, bool estaVivo)
	{
		Vilgax* v1 = new Vilgax(sf::Vector2f(x, y));
		v1->setVivo(estaVivo);
		Entidade* e1 = static_cast <Entidade*>(v1);
		LEnt.addEntidade(e1);
		Inimigo* i1 = static_cast <Inimigo*>(v1);
		Ger.getVecInimigos()->push_back(i1);
	}

	void Fase_Primeira::criaEspinhos()
	{
		int n = 3 + rand() % 3;
		for (int i = 0; i < n; i++)
		{
			Espinhos* es1 = new Espinhos(sf::Vector2f(100.f + 100.f * i, 0.f), sf::Vector2f(35.f, 25.f + 5*i), 25.f + 5 * i);
			Entidade* e1 = static_cast <Entidade*>(es1);
			LEnt.addEntidade(e1);
			Ger.getListObst()->push_back(es1);
		}
	}

	void Fase_Primeira::criaEspinhos(float x, float y, float tamx, float tamy, float altura)
	{
		Espinhos* es1 = new Espinhos(sf::Vector2f(x, y), sf::Vector2f(tamx, tamy), altura);
		Entidade* e1 = static_cast <Entidade*>(es1);
		LEnt.addEntidade(e1);
		Ger.getListObst()->push_back(es1);
	}

	void Fase_Primeira::criaPlataformas() 
	{
		Plataforma* plat = new Plataforma();
		LEnt.addEntidade(plat);
		Ger.getListObst()->push_back(plat);
	}
}