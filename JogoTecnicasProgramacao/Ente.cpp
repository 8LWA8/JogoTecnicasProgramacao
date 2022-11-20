#include "Ente.h"

Ente::Ente() : corpo(sf::Vector2f(100.f, 100.f)),
textura(NULL),
id(0)
{
	pGerenteGrafico = GerenteGrafico::getInstance();
}

Ente::~Ente()
{
}

void Ente::setId(int id) 
{
	this->id = id;
}

int Ente::getId() const
{
	return id;
}


//void Ente::imprimir() {}

void Ente::setTextura(const char* path) 
{
	this->textura = pGerenteGrafico->loadTexture(path);
	this->corpo.setTexture(textura);
}

sf::RectangleShape* Ente::getCorpo() 
{
	return &corpo;
}

