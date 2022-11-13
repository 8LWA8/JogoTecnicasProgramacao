#include "GerenteColisoes.h"
using namespace Entidades;

namespace Gerenciadores {

	GerenteColisoes::GerenteColisoes() {};
	GerenteColisoes::~GerenteColisoes() {};

	void GerenteColisoes::checkCollision(Entidade* ent1, Entidade* ent2)
	{

		Coord* coord1 = ent1->getCoord();
		Coord* coord2 = ent2->getCoord();
		Coord* tam1 = ent1->getTam();
		Coord* tam2 = ent2->getTam();

		//Utilizados para os calculos de colisao no eixo X
		float x1 = ent1->getCoord()->getX();
		float x2 = ent2->getCoord()->getX();

		float tx1 = ent1->getTam()->getX();
		float tx2 = ent2->getTam()->getX();
		
		//Utilizados para os calculos de colisao no eixo Y
		float y1 = ent1->getCoord()->getY();
		float y2 = ent2->getCoord()->getY();

		float ty1 = ent1->getTam()->getY();
		float ty2 = ent2->getTam()->getY();

		//Calculos
		float dx = abs((x1 + (tx1 / 2)) - (x2 + (tx2 / 2)) - (tx1 + tx2));
		float dy = abs((y1 + (ty1 / 2)) - (y2 + (ty2 / 2)) - (ty1 + ty2));
		

		Coord* coll1 = ent1->getColl();
		Coord* coll2 = ent2->getColl();
		if (dx <= 0.0) 
		{
			if (coord1->getX() > coord2->getX()) 
			{
				coll1->setValX(1.0);
				coll2->setValX(-1.0);
			}
			else 
			{
				coll1->setValX(-1.0);
				coll2->setValX(1.0);
			}

		}
		else 
		{
			coll1->setValX(0.0);
			coll2->setValX(0.0);
		}

		if (dy <= 0.0)
		{
			if (coord1->getY() > coord2->getY())
			{
				coll1->setValY(1.0);
				coll2->setValY(-1.0);
			}
			else
			{
				coll1->setValY(-1.0);
				coll2->setValY(1.0);
			}

		}
		else
		{
			coll1->setValY(0.0);
			coll2->setValY(0.0);
		}

	}


	

}

