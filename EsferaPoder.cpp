#include "EsferaPoder.h"
#include <stdlib.h>
#include <iostream>

EsferaPoder::EsferaPoder(): coletada(false)
{
	setTextura("assets\\textures\\EsferaPoder.png");
	corpo.setSize(sf::Vector2f(25.f, 25.f));
	int p = rand() % 500;
	corpo.setPosition(sf::Vector2f(-600.f + (float) p, 150.f));
}

EsferaPoder::EsferaPoder(const sf::Vector2f pos): coletada(false)
{
	setTextura("assets\\textures\\EsferaPoder.png");
	corpo.setSize(sf::Vector2f(25.f, 25.f));
	corpo.setPosition(sf::Vector2f(pos));
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
	if (coletada == false)
	{
		imprimir();
		sofrer_gravidade();
		anularGravidade();
	}
}

void EsferaPoder::danar(Entidade* ent)
{
}

void EsferaPoder::anularGravidade()
{
	corpo.move(sf::Vector2f(0.f, -0.5));
	coordenada.addY(-0.5);
}

void EsferaPoder::salvar() 
{
	std::ofstream dadosEsfera;

	dadosEsfera.open("salvar/salvarEsfera.txt", std::ios::app);

	if (!dadosEsfera.is_open())
	{
		std::cout << "ERRO ABRINDO salvarEspi.txt" << std::endl;
		exit(1);
	}

	std::cout << "entrou salvar esferas" << std::endl;

	dadosEsfera << corpo.getPosition().x << " ";
	dadosEsfera << corpo.getPosition().y << " ";
	dadosEsfera << getColetada() << " ";

	dadosEsfera << std::endl;
	dadosEsfera.close();
}