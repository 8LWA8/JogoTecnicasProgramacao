#include "GerenteColisoes.h"
#include "Inimigo.h"
#include "Jogador.h"

#define WIDTH 1200

using namespace Entidades;
using namespace Personagens;

namespace Gerenciadores {

	GerenteColisoes::GerenteColisoes(/*ListaEntidades* pL*/)
	{
		//pLista = pL;
	};

	GerenteColisoes::~GerenteColisoes() {};

	//Função inspirada no vídeo: https://www.youtube.com/watch?v=A04MPkBL5H4
	bool GerenteColisoes::verificaColisao(Entidade* ent1, Entidade* ent2)
	{
		//Coll: 1.0 (colisão na direita ou embaixo) -1.0 (colisão em cima ou na esquerda)
		Coord* coll1 = ent1->getColl(); 
		Coord* coll2 = ent2->getColl();

		sf::FloatRect nextPos1;
		sf::FloatRect nextPos2;
		sf::FloatRect ent1Bounds = ent1->getCorpo()->getGlobalBounds();
		sf::FloatRect ent2Bounds = ent2->getCorpo()->getGlobalBounds();

		nextPos1 = ent1Bounds;
		nextPos1.left += ent1->getVel()->getX();
		nextPos1.top += ent1->getVel()->getY();

		nextPos2 = ent2Bounds;
		nextPos2.left += ent2->getVel()->getX();
		nextPos2.top += ent2->getVel()->getY();

		if (ent2Bounds.intersects(nextPos1))
		{
			//Colisao em cima
			if (colideEmcima(ent1Bounds, ent2Bounds) == true)
			{
				coll1->setValY(-1.0); //colide em cima
				coll2->setValY(1.0); //colide embaixo
			}

			//Colisao direita
			if (colideDireita(ent1Bounds, ent2Bounds) == true)
			{
				//std::cout << "COLISAO DIREITA" << std::endl;
				coll1->setValX(1.0); //colide pela direita
				coll2->setValX(-1.0); //colide pela esquerda
			}

			//Colisao esquerda
			if (colideEsquerda(ent1Bounds, ent2Bounds) == true)
			{
				//std::cout << "COLISAO ESQUERDA" << std::endl;
				coll1->setValX(-1.0); //colide pela esquerda
				coll2->setValX(1.0); //colide pela direita
			}

			//Colisao embaixo
			if (colideEmbaixo(ent1Bounds, ent2Bounds) == true)
			{
				//FAZ O JOGADOR PULAR SE BATER COM UM INIMIGO POR CIMA
				if (ent2->getId() == 2) {
					ent1->getCorpo()->move(sf::Vector2f(0.0f, -200.0f));
				} 
				coll1->setValY(1.0); //colide embaixo
				coll2->setValY(-1.0); //colide em cima
			}

			return true;
		}
		else
		{
			return false;
		}
	}

	bool GerenteColisoes::colideEmbaixo(sf::FloatRect ent1Bounds, sf::FloatRect ent2Bounds)
	{
		if (ent1Bounds.top < ent2Bounds.top
			&& ent1Bounds.top + ent1Bounds.height < ent2Bounds.top + ent2Bounds.height
			&& ent1Bounds.left < ent2Bounds.left + ent2Bounds.width
			&& ent1Bounds.left + ent1Bounds.width > ent2Bounds.left
			)
		{
			return true;
		}
		return false;
	}

	bool GerenteColisoes::colideEmcima(sf::FloatRect ent1Bounds, sf::FloatRect ent2Bounds)
	{
		if (ent1Bounds.top > ent2Bounds.top
			&& ent1Bounds.top + ent1Bounds.height > ent2Bounds.top + ent2Bounds.height
			&& ent1Bounds.left < ent2Bounds.left + ent2Bounds.width
			&& ent1Bounds.left + ent1Bounds.width > ent2Bounds.left)
		{
			return true;
		}
		return false;
	}

	bool GerenteColisoes::colideDireita(sf::FloatRect ent1Bounds, sf::FloatRect ent2Bounds)
	{
		if (ent1Bounds.left < ent2Bounds.left
			&& ent1Bounds.left + ent1Bounds.width < ent2Bounds.left + ent2Bounds.width
			&& ent1Bounds.top < ent2Bounds.top + ent2Bounds.height
			&& ent1Bounds.top + ent1Bounds.height > ent2Bounds.height)
		{
			return true;
		}
		return false;
	}

	bool GerenteColisoes::colideEsquerda(sf::FloatRect ent1Bounds, sf::FloatRect ent2Bounds)
	{
		if (ent1Bounds.left > ent2Bounds.left
			&& ent1Bounds.left + ent1Bounds.width > ent2Bounds.left + ent2Bounds.width
			&& ent1Bounds.top < ent2Bounds.top + ent2Bounds.height
			&& ent1Bounds.top + ent1Bounds.height > ent2Bounds.height)
		{
			return true;
		}
		return false;
	}


	//Função inspirada no vídeo: https://www.youtube.com/watch?v=onRDXY6WoVk
	void GerenteColisoes::colideCanto(Entidade* ent)
	{
		if (ent->getCorpo()->getPosition().x < -WIDTH/2)
		{
			ent->getCorpo()->setPosition(-WIDTH/2, ent->getCorpo()->getPosition().y);
		}
		//cout << ent->getCorpo()->getPosition().x << endl;
		if (ent->getCorpo()->getPosition().x + ent->getCorpo()->getGlobalBounds().width> WIDTH/2)
		{
			ent->getCorpo()->setPosition(WIDTH/2 - ent->getCorpo()->getGlobalBounds().width, ent->getCorpo()->getPosition().y);
		}
	}

	/*void GerenteColisoes::checaColisaoLista(Entidade* ent1)
	{
		int tam = pLista->getTam();
		Entidade* aux = nullptr;
		for (int i = 0; i < tam; i++)
		{
			cout << "loop exetds" << endl;
			aux = pLista->operator[](i);
			if (Personagem* p = dynamic_cast <Personagem*>(aux))
			{
				if (p->getVivo() == true)
				{
					verificaColisao(ent1, aux);
				}
			}
			else
			{
				verificaColisao(ent1, aux);
			}
		}
	}*/

	void GerenteColisoes::checaColisaoObst(Entidade* ent)
	{
		list <Obstaculo*>::iterator it;
		for (it=LOs.begin(); it!=LOs.end(); it++)
		{
			if (verificaColisao(ent, *it) == true && (*it)->getCausa_dano() == true)
			{
				if (Jogador* j = dynamic_cast <Jogador*>(ent))
				{
					(*it)->danar(ent);
				}
			}
		}
	}
	void GerenteColisoes::checaColisaoIni(Entidade* ent)
	{
		vector <Inimigo*>::iterator it;
		for (it = LIs.begin(); it != LIs.end(); it++)
		{
			colideCanto(*it);
			if ((*it)->getVivo() == true)
			{
				if (verificaColisao(ent, *it))
				{
					if (Jogador* j = dynamic_cast <Jogador*>(ent))
					{
						if (j->getEmpoderado() == true)
						{
							(*it)->setVivo(false);
							//SOMAR PONTUAÇÃO
						}
						else
						{
							(*it)->danar(ent);
						}
					}
				}
			}
		}
	}
	void GerenteColisoes::checaColisaoEsfera(Jogador* jog)
	{
		vector <EsferaPoder*>::iterator it;
		for (it = LPs.begin(); it != LPs.end(); it++)
		{
			if ((*it)->getColetada() == false)
			{
				if (verificaColisao(jog, *it) == true)
				{
					(*it)->setColetada(true);
					jog->ficarEmpoderado();
				}
			}
		}
	}
}
	


	


