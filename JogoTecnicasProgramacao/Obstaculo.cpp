#include "Obstaculo.h"
#include <iostream>
using namespace Entidades::Obstaculos;

Obstaculo::Obstaculo() :
	causa_dano(false)
{
	this->dano = 0.0;
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::executar()
{
	Obstaculo::imprimir();
	sofrer_gravidade();
}

void Obstaculo::danar(Entidade* ent) 
{
	
}