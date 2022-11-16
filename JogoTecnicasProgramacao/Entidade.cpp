#include "Entidade.h"
#include <iostream>
using namespace Entidades;

Entidade::Entidade() : coordenada(0.0, 0.0),
tam(0.0, 0.0),
vel(0.1, 0.1),
coll(0.0, 0.0),
mov(false), mov_dir(false), mov_esq(false)
{
	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	//coordenada.setVal(corpo.getPosition().x, corpo.getPosition().y);
	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);

}

Entidade::~Entidade()
{
}

Coord* Entidade::getCoord() 
{

	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	//coordenada.setVal(corpo.getPosition().x, corpo.getPosition().y);
	return &coordenada;
};

Coord* Entidade::getTam() 
{
	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);
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

void Entidade::resetColl() 
{
	coll.setVal(0.0, 0.0);
}

bool Entidade::getMov() const
{
	return mov;
}

void Entidades::Entidade::setMov(bool m)
{
	mov = m;
}

void Entidades::Entidade::setMovDir(bool m)
{
	mov_dir = m;
}

void Entidades::Entidade::setMovEsq(bool m)
{
	mov_esq = m;
}
