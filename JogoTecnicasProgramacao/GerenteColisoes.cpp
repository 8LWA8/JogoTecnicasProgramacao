#include "GerenteColisoes.h"
#include "Inimigo.h"

using namespace Entidades;
using namespace Personagens;

namespace Gerenciadores {

	GerenteColisoes::GerenteColisoes(/*ListaEntidades* pL*/)
	{
		//pLista = pL;
	};

	GerenteColisoes::~GerenteColisoes() {};

	//Função inspirada no vídeo: https://www.youtube.com/watch?v=A04MPkBL5H4
	void GerenteColisoes::verificaColisao(Entidade* ent1, Entidade* ent2)
	{
		//ent1 = jogador
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
				coll1->setValY(1.0); //colide embaixo
				coll2->setValY(-1.0); //colide em cima

				//if (ent2->getMov() == true && coll1->getY()==1.0)
				//{
				//	if (Personagem* p = dynamic_cast <Personagem*>(ent2))
				//	{
				//		p->setVivo(false);
				//	}
				//}

			}
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
			verificaColisao(ent, *it);
		}
	}
	void GerenteColisoes::checaColisaoIni(Entidade* ent)
	{
		vector <Inimigo*>::iterator it;
		for (it = LIs.begin(); it != LIs.end(); it++)
		{
			verificaColisao(ent, *it);
		}
	}
}
	


	


