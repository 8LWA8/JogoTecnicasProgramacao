#include "Entidade.h"
#include <iostream>
using namespace Entidades;

Entidade::Entidade(): coordenada(0.0,0.0),
tam(0.0,0.0),
vel(0.1, 0.1),
coll(0.0,0.0)
{
	coordenada.setVal(corpo.getPosition().x, corpo.getPosition().y);
	tam.setVal(corpo.getSize().x, corpo.getSize().y);

}

Entidade::~Entidade()
{
}

Coord* Entidade::getCoord() 
{

	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	return &coordenada;
};

Coord* Entidade::getTam() 
{
	//tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);
	return &tam;
}

Coord* Entidade::getVel() 
{
	return &vel;
}

Coord* Entidade::getColl() 
{

	return &coll;
}


void Entidade::imprimir() 
{
	//std::cout << "imprimiu ent" << std::endl;
	GerenteGrafico* pGerenteGraf = GerenteGrafico::getInstance();
	//pGerenteGraf->CenterView(pos);
	pGerenteGraf->render(&corpo);

}

