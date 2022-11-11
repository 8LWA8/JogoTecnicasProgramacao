#include "Personagem.h"

using namespace Entidades::Personagens;

Personagem::Personagem(): num_vidas(0)
{
}

Personagem::~Personagem()
{
}

void Entidades::Personagens::Personagem::executar()
{
	imprimir();
}
