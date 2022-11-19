#include "EsferaPoder.h"
#include <stdlib.h>
#include <iostream>

EsferaPoder::EsferaPoder(): coletada(false)
{
	setTextura("EsferaPoder.png");
	corpo.setSize(sf::Vector2f(25.f, 25.f));
	int p = rand() % 500;
	corpo.setPosition(sf::Vector2f(-600.f + (float) p, 150.f));
}

EsferaPoder::~EsferaPoder()
{
}

void EsferaPoder::setColetada(bool c)
{
	coletada = c;
}

bool EsferaPoder::getColetada()
{
	return coletada;
}

void EsferaPoder::executar()
{
	imprimir();
}

void EsferaPoder::danar(Entidade* ent)
{
}
