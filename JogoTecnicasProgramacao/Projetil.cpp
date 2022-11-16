#include "Projetil.h"

using namespace Entidades;

void Projetil::setDano(int d) 
{
	if (d > 0)
		this->dano = d;
	else
		this->dano = 0;
}
int Projetil::getDano() const
{
	return dano;
}