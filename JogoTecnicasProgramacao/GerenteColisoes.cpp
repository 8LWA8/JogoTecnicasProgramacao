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
		
		//TESTE
		//std::cout << "1 " << coord1->getX() << " " << coord1->getY() << " | " << tam1->getX() << " " << tam1->getY() <<   std::endl;
		//std::cout << "2 " << coord2->getX() << " " << coord2->getY() << " | "  << tam2->getX() << " " << tam2->getY() << std::endl;
		//TESTE


	
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
		float dx = abs((x1) - (x2)) - (tx1 + tx2) / 2;
		//float dy = abs((y1 + (ty1 / 2)) - (y2 + (ty2 / 2)) - (ty1 + ty2)/2);
		float dy = abs((y1) - (y2)) - (ty1 + ty2) / 2;
		

		Coord* coll1 = ent1->getColl();
		Coord* coll2 = ent2->getColl();
		
		//TESTE
		std::cout << " 1 --> " << coll1->getX() << " | " << coll1->getY() << " || " << coord1->getX() << " | " << coord1->getY() << " || " << tam1->getX() << " | " << tam1->getY() << std::endl;
		std::cout << " 2 --> " << coll2->getX() << " | " << coll2->getY() << " || " << coord2->getX() << " | " << coord2->getY() << " || " << tam2->getX() << " | " << tam2->getY() << std::endl;
		//TESTE

		std::cout << "dx " << dx  << std::endl;
		std::cout << "dy " << dx << std::endl;
		if (dy == 0.0)
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
		else if (dx == 0.0)
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
	}


	

}

