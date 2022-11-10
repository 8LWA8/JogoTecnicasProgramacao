#include "GerenteColisoes.h"
using namespace Entidades;

namespace Gerenciadores {

	GerenteColisoes::GerenteColisoes() {};
	GerenteColisoes::~GerenteColisoes() {};

	void GerenteColisoes::checkCollision(Entidade* ent1, Entidade* ent2)
	{
		/*
		int x1 = ent1->getPos();
		int x2 = ent2->getPos();
		int dx = abs((x1 + 50)- (x2 + 50))- (50+50);
			*/

		Coord* coord1 = ent1->getCoord();
		Coord* coord2 = ent2->getCoord();
		Coord* tam1 = ent1->getTam();
		Coord* tam2 = ent2->getTam();

		float dx = abs((coord1->x + (tam1->x / 2)) - (coord2->x + (tam2->x / 2)) - (tam1->x + tam2->x));
		float dy = abs((coord1->y + (tam1->y / 2)) - (coord2->y + (tam2->y / 2)) - (tam1->y + tam2->y));

		if (dx < 0.0 || dy < 0.0) 
		{
			exit(1);
		}

	}

}