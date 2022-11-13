#include "Personagem.h"
#include <iostream>
using namespace Entidades::Personagens;

Personagem::Personagem(): num_vidas(0)
{
}

Personagem::~Personagem()
{
}

void Entidades::Personagens::Personagem::executar()
{
	std::cout << "PERSONAGEM EXE" << std::endl;
	imprimir();
}
