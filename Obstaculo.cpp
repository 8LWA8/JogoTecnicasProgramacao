#include "Obstaculo.h"
#include <iostream>
using namespace Entidades::Obstaculos;

Entidades::Obstaculos::Obstaculo::Obstaculo(): causa_dano(false)
{
}

Entidades::Obstaculos::Obstaculo::~Obstaculo()
{
}

void Entidades::Obstaculos::Obstaculo::executar()
{
	Obstaculo::imprimir();
	sofrer_gravidade();
}
