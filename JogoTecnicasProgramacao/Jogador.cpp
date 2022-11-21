#include "Jogador.h"
#include <iostream>
using namespace Entidades::Personagens;



Jogador::Jogador(): pontuacao(0), empoderado(false)
{
    corpo.setSize(sf::Vector2f(35.f, 70.f));
    corpo.setPosition(sf::Vector2f(0.f, 100.f));
    vel.setVal(3.0, 1.0);
    mov = true;
}

Jogador::~Jogador()
{
}


void Jogador::executar()
{
	this->imprimir();
    this->mover();
    this->resetColl();
    if (empoderado == true)
    {
        float dt = relogio.getElapsedTime().asSeconds();
        if (dt >= 3.0f)
        {
            empoderado = false;
            corpo.setFillColor(sf::Color::White);
            relogio.restart();
        }
    }

    if (corpo.getFillColor() == sf::Color::Red)
    {
        float dt = relogio.getElapsedTime().asSeconds();
        if (dt >= 1.0f)
        {
            corpo.setFillColor(sf::Color::White);
            relogio.restart();
        }
    }
}





void Jogador::setPontuacao(int p)
{
    this->pontuacao = p;
}
int Jogador::getPontuacao()
{
    return pontuacao;
}

void Jogador::ficarEmpoderado()
{
    relogio.restart();
    empoderado = true;
    corpo.setFillColor(sf::Color::Blue);
}

bool Jogador::getEmpoderado()
{
    return empoderado;
}




void Jogador::levarDano(float dano)
{
    if (this->empoderado == false) {
        this->num_vidas = this->num_vidas - dano;
        //std::cout << num_vidas << std::endl;
        corpo.setFillColor(sf::Color::Red);
    }
    if (this->num_vidas <= 0.0) 
    {
        Jogador::setVivo(false);
    }
}


