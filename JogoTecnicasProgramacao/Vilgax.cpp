#include "Vilgax.h"
using namespace Entidades::Personagens;

Vilgax::Vilgax():poder_dano(2.0)
{
	this->setDano(0.5 * poder_dano);
	setTextura("assets\\textures\\vilgax.png");
	corpo.setSize(sf::Vector2f(150.f, 150.f));
	corpo.setPosition(sf::Vector2f(0.f, 0.f));
}

Vilgax::Vilgax(const sf::Vector2f pos):poder_dano(2.0)
{
	this->setDano(0.5 * poder_dano);
	setTextura("assets\\textures\\vilgax.png");
	corpo.setSize(sf::Vector2f(150.f, 150.f));
	corpo.setPosition(pos);
}

Vilgax::~Vilgax()
{

}

void Vilgax::salvar()
{
    std::ofstream dadosVilgax;

    dadosVilgax.open("salvar/salvarVilgax.txt", std::ios::app);

    if (!dadosVilgax.is_open())
    {
        std::cout << "ERRO ABRINDO salvarVilgax.txt" << std::endl;
        exit(1);
    }

    std::cout << "entrou salvar vilgax" << std::endl;

    dadosVilgax << corpo.getPosition().x << " ";
    dadosVilgax << corpo.getPosition().y << " ";
    dadosVilgax << getVivo() << " ";

    dadosVilgax << std::endl;
    dadosVilgax.close();
}

void Vilgax::setPoderDano(float d)
{
	this->poder_dano = d;
}
float Vilgax::getPoderDano() 
{
	return poder_dano;
}