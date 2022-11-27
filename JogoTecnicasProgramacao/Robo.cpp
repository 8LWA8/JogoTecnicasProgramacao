#include "Robo.h"
#include <stdlib.h>
#include <time.h>
//#include <iostream>
using namespace Entidades::Personagens;

Entidades::Personagens::Robo::Robo()
{
	setTextura("assets\\textures\\robo_parado.png");
	corpo.setSize(sf::Vector2f(70.f, 70.f));
	corpo.setPosition(sf::Vector2f(100.f, 100.f));
}

Entidades::Personagens::Robo::Robo(const sf::Vector2f pos)
{
	setTextura("assets\\textures\\robo_parado.png");
	corpo.setSize(sf::Vector2f(70.f, 70.f));
	corpo.setPosition(pos);
}

Entidades::Personagens::Robo::~Robo()
{
}

void Robo::salvar()
{
    std::ofstream dadosRobo;

    dadosRobo.open("salvar/salvarRobo.txt", std::ios::app);

    if (!dadosRobo.is_open())
    {
        std::cout << "ERRO ABRINDO salvarJog.txt" << std::endl;
        exit(1);
    }

    std::cout << "entrou salvar robo" << std::endl;

  /*  dadosRobo << getId() << " ";*/
    dadosRobo << corpo.getPosition().x << " ";
    dadosRobo << corpo.getPosition().y << " ";
    //dadosRobo << num_vidas << " ";
    dadosRobo << getVivo() << " ";
    /*dadosJogador << getColl()->getX() << " ";
    dadosJogador << getColl()->getY() << " ";*/

    dadosRobo << std::endl;
    dadosRobo.close();
}

//void Entidades::Personagens::Robo::executar()
//{
//	Robo::imprimir();
//}
