#include "Ente.h"

Ente::Ente() : corpo(sf::Vector2f(100.f, 100.f)),
pGerenteGrafico()
{
	pGerenteGrafico = GerenteGrafico::getInstance();
}

Ente::~Ente()
{
}



//void Ente::imprimir() {}

void Ente::setTextura(const char* path) 
{
	this->textura = pGerenteGrafico->loadTexture(path);
	this->corpo.setTexture(textura);
}