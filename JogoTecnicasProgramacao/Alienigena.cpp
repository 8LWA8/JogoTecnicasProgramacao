#include "Alienigena.h"
using namespace Entidades::Personagens;

Alienigena::Alienigena(const sf::Vector2f pos)//: atirou(false)
{
	this->setId(6);
	setTextura("assets\\textures\\alien_parado.png");
	corpo.setSize(sf::Vector2f(40.f, 80.f));
	corpo.setPosition(pos);

	coordenada.setVal(corpo.getGlobalBounds().left, corpo.getGlobalBounds().top);
	tam.setVal(corpo.getGlobalBounds().width, corpo.getGlobalBounds().height);

	//proj.getCorpo()->setPosition(sf::Vector2f(corpo.getPosition().x, corpo.getPosition().y));
	proj = new Projetil(sf::Vector2f(corpo.getPosition().x, corpo.getPosition().y));
}

Alienigena::~Alienigena()
{
}

void Alienigena::executar()
{
	if (vivo == true)
	{
		this->imprimir();
		this->atirar();
		this->moveAleatorio();
		this->resetColl();
	}
	else
	{
		proj->setExiste(false);
	}
}

void Alienigena::atirar()
{
	//setAtirou(true);
	proj->recebePosAlien(corpo.getPosition());
	proj->executar();
}

void Entidades::Personagens::Alienigena::salvar()
{
	std::ofstream dadosAlien;

	dadosAlien.open("salvar/salvarAlien.txt", std::ios::app);

	if (!dadosAlien.is_open())
	{
		std::cout << "ERRO ABRINDO salvarAlien.txt" << std::endl;
		exit(1);
	}

	std::cout << "entrou salvar alien" << std::endl;

	dadosAlien << corpo.getPosition().x << " ";
	dadosAlien << corpo.getPosition().y << " ";
	dadosAlien << getVivo() << " ";
	dadosAlien << getProj()->getCorpo()->getPosition().x << " ";
	dadosAlien << getProj()->getCorpo()->getPosition().y << " ";
	dadosAlien << getProj()->getAtingiu() << " ";
	dadosAlien << getProj()->getExiste() << " ";

	dadosAlien << std::endl;
	dadosAlien.close();
}


//void Alienigena::setAtirou(bool estado) 
//{
//	this->atirou = estado;
//}

Entidades::Projetil* Alienigena::getProj()
{
	return proj;
}


//
//bool Alienigena::getAtirou() 
//{
//	return this->atirou;
//}
