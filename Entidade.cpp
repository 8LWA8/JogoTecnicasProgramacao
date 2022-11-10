#include "Entidade.h"

using namespace Entidades;

Entidade::Entidade(): coordenada(),
tam()
{
	coordenada.x = corpo.getPosition().x;
	coordenada.y = corpo.getPosition().y;
	tam.x = corpo.getSize().x;
	tam.y = corpo.getSize().y;

}

Entidade::~Entidade()
{
}

Coord* Entidade::getCoord() 
{
	return &coordenada;
};

Coord* Entidade::getTam() 
{
	return &tam;
}


void Entidade::imprimir() 
{
	GerenteGrafico* pGerenteGraf = GerenteGrafico::getInstance();
	//pGerenteGraf->CenterView(pos);
	pGerenteGraf->render(&corpo);

}