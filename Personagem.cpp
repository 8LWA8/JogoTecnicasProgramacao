#include "Personagem.h"
#include <iostream>
using namespace Entidades::Personagens;

Personagem::Personagem(): num_vidas(0), vivo(true)
{
}

Personagem::~Personagem()
{
}

void Entidades::Personagens::Personagem::setVivo(bool v)
{
	vivo = v;
}

bool Entidades::Personagens::Personagem::getVivo()
{
	return vivo;
}

void Entidades::Personagens::Personagem::executar()
{
	//std::cout << "PERSONAGEM EXE" << std::endl;
	imprimir();
}
