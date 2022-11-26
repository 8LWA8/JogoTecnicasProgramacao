#include "Rocha.h"
using namespace Entidades::Obstaculos;

Entidades::Obstaculos::Rocha::Rocha()
{
	setTextura("rocha.png");
	corpo.setSize(sf::Vector2f(40.f, 35.f));
	corpo.setPosition(sf::Vector2f(-600.f, 200.f));
}

Entidades::Obstaculos::Rocha::Rocha(const sf::Vector2f pos)
{
	setTextura("rocha.png");
	corpo.setSize(sf::Vector2f(40.f, 35.f));
	corpo.setPosition(pos);
}

Entidades::Obstaculos::Rocha::~Rocha()
{
}

void Entidades::Obstaculos::Rocha::salvar()
{
    std::ofstream dadosRocha;

    dadosRocha.open("salvar/salvarRocha.txt", std::ios::app);

    if (!dadosRocha.is_open())
    {
        std::cout << "ERRO ABRINDO salvarRocha.txt" << std::endl;
        exit(1);
    }

    std::cout << "entrou salvar rocha" << std::endl;

    dadosRocha << corpo.getPosition().x << " ";
    dadosRocha << corpo.getPosition().y << " ";

    dadosRocha << std::endl;
    dadosRocha.close();
}
