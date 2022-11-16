#include "GerenteColisoes.h"

using namespace Entidades;

namespace Gerenciadores {

	GerenteColisoes::GerenteColisoes() {};
	GerenteColisoes::~GerenteColisoes() {};

	void GerenteColisoes::verificaColisaoHor(Entidade* ent1, Entidade* ent2)
	{
		/*float x1 = ent1->getCoord()->getX();
		float x2 = ent2->getCoord()->getX();

		float tx1 = ent1->getTam()->getX();
		float tx2 = ent2->getTam()->getX();

		float y1 = ent1->getCoord()->getY();
		float y2 = ent2->getCoord()->getY();

		float ty1 = ent1->getTam()->getY();
		float ty2 = ent2->getTam()->getY();

		//if (x1 + tx1 == x2)
			//&& y1 + ty1 >=y2 && y1>=y2+ty2)
		//{
		//	std::cout << "colisao hor dir" << std::endl;
			//ent1->setMovDir(false);
		//}
		//else
		//{
		//	ent1->setMovDir(true);
		//}

		//if (x2 + tx2 == x1)
			//&& y2 + ty2 >= y1 && y2 >= y1 + ty1)
		//{
		//	std::cout << "colisao hor esq" << std::endl;
		//	ent1->setMovEsq(false);
		//}
		//else
		//{
		//	ent1->setMovEsq(true);
		//}
		*/

		sf::FloatRect nextPos;
		sf::FloatRect playerBounds = ent1->getCorpo()->getGlobalBounds();
		sf::FloatRect objBounds = ent2->getCorpo()->getGlobalBounds();

		nextPos = playerBounds;
		nextPos.left += ent1->getVel()->getX();
		nextPos.top += ent1->getVel()->getY();

		if (objBounds.intersects(nextPos))
		{
			//Colisao direita
			if (playerBounds.left < objBounds.left
				&& playerBounds.left + playerBounds.width < objBounds.left + objBounds.width
				&& playerBounds.top < objBounds.top + objBounds.height
				&& playerBounds.top + playerBounds.height > objBounds.height)
			{
				std::cout << "COLISAO DIREITA" << std::endl;
				ent1->setMovDir(false);
				//ent1->getCorpo()->setPosition(objBounds.left - playerBounds.width, playerBounds.top);
			}
			
			//Colisao esquerda
			if (playerBounds.left > objBounds.left
				&& playerBounds.left + playerBounds.width > objBounds.left + objBounds.width
				&& playerBounds.top < objBounds.top + objBounds.height
				&& playerBounds.top + playerBounds.height > objBounds.height)
			{
				std::cout << "COLISAO ESQUERDA" << std::endl;
				ent1->setMovEsq(false);
				//ent1->getCorpo()->setPosition(objBounds.left + playerBounds.width, playerBounds.top);
			}
		}
		else
		{
			ent1->setMovDir(true);
			ent1->setMovEsq(true);
		}
	
	}

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

		//float x1 = 0.0, x2 = 0.0, tx1 = 0.0, tx2 = 0.0, y1 = 0.0, y2 = 0.0, ty1=0;

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
		float dx = 0, dy = 0;
		dx = abs(x1 - x2) - ((tx1 + tx2) / 2);
		//float dy = abs((y1 + (ty1 / 2)) - (y2 + (ty2 / 2)) - (ty1 + ty2)/2);
		dy = abs(y1 - y2) - ((ty1 + ty2) / 2);


		Coord* coll1 = ent1->getColl();
		Coord* coll2 = ent2->getColl();

		//TESTE
		//std::cout << " 1 --> " << coll1->getX() << " | " << coll1->getY() << " || " << coord1->getX() << " | " << coord1->getY() << " || " << tam1->getX() << " | " << tam1->getY() << std::endl;
		//std::cout << " 2 --> " << coll2->getX() << " | " << coll2->getY() << " || " << coord2->getX() << " | " << coord2->getY() << " || " << tam2->getX() << " | " << tam2->getY() << std::endl;
		//std::cout << "dx " << dx  << std::endl;
		//std::cout << "dy " << dy << std::endl;
		//TESTE

		if (dy <= 0.0 && ((x1 <= x2 && x2 <= (x1 + tx1)) || (x2 <= x1 && x1 <= (x2 + tx2))))
		{
			if (coord1->getY() > coord2->getY())
			{
				coll1->setValY(1.0);
				coll2->setValY(-1.0);
				/*
				//TESTE de possivel aplicacao
				ent1->getCorpo()->move(sf::Vector2f(0.0f,dy/2));
				coord1->addY(dy/2);

				ent2->getCorpo()->move(sf::Vector2f(0.0f, -dy / 2));
				coord2->addY(-dy / 2);
				//TESTE de possivel aplicacao
				*/
			}
			else
			{
				coll1->setValY(-1.0);
				coll2->setValY(1.0);

				/*
				//TESTE de possivel aplicacao
				ent1->getCorpo()->move(sf::Vector2f(0.0f, -dy / 2));
				coord1->addY(-dy / 2);

				ent2->getCorpo()->move(sf::Vector2f(0.0f, dy / 2));
				coord2->addY(dy / 2);
				//TESTE de possivel aplicacao
				*/
			}

		}
		/*else if (dx <= 0.0 && ((y1 <= y2 && y2 <= (y1 + ty1)) || (y2 <= y1 && y1 <= (y2 + ty2))))
		{
			std::cout << "col" << std::endl;
			if (dx <= 0.0)
			{
				std::cout << "dx" << std::endl;
			}
			if (coord1->getX() > coord2->getX())
			{
				coll1->setValX(1.0);
				coll2->setValX(-1.0);

				//TESTE de possivel aplicacao
				std::cout << "1" << std::endl;
				if (ent1->getMov() && ent2->getMov()) {
					ent1->getCorpo()->move(sf::Vector2f(dx / 2, 0.0f));
					coord1->addX(dx / 2);

					ent2->getCorpo()->move(sf::Vector2f(-dx / 2, 0.0f));
					coord2->addX(-dx / 2);
				}
				else if (ent1->getMov())
				{
					ent1->getCorpo()->move(sf::Vector2f(dx, 0.0f));
					coord1->addX(dx);

				}
				else
				{
					ent2->getCorpo()->move(sf::Vector2f(-dx, 0.0f));
					coord2->addX(-dx);
				}
				//TESTE de possivel aplicacao
			}
			else
			{
				std::cout << "2" << std::endl;
				coll1->setValX(-1.0);
				coll2->setValX(1.0);

				//TESTE de possivel aplicacao
				if (ent1->getMov() && ent2->getMov()) {
					ent1->getCorpo()->move(sf::Vector2f(-dx / 2, 0.0f));
					coord1->addX(-dx / 2);

					ent2->getCorpo()->move(sf::Vector2f(dx / 2, 0.0f));
					coord2->addX(dx / 2);
					std::cout << "3" << std::endl;
				}
				else if (ent1->getMov())
				{
					std::cout << "4" << std::endl;
					ent1->getCorpo()->move(sf::Vector2f(-dx, 0.0f));
					coord1->addX(-dx);
				}
				else
				{
					std::cout << "5" << std::endl;
					ent2->getCorpo()->move(sf::Vector2f(dx, 0.0f));
					coord2->addX(dx);
				}
				//TESTE de possivel aplicacao
			}

			
		}*/


	}
}
	


	


