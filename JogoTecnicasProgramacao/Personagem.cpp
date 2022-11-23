#include "Personagem.h"
#include <iostream>
using namespace Entidades::Personagens;

Personagem::Personagem(): num_vidas(0.0), vivo(true)
{
}

Personagem::~Personagem()
{
}

void Personagem::setVivo(bool v)
{
	vivo = v;
}

bool Personagem::getVivo()
{
	return vivo;
}

void Personagem::executar()
{
	//std::cout << "PERSONAGEM EXE" << std::endl;
	imprimir();
}


float Personagem::getNumVidas() 
{
	return this->num_vidas;
}

void Personagem::setNumVidas(float vidas)
{
	num_vidas = vidas;
}

void Personagem::danar(Entidade* ent) {}

void Personagem::salvar() {}