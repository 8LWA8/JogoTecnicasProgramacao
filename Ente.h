#pragma once
#include <SFML/Graphics.hpp>

#include "GerenteGrafico.h"
using namespace Gerenciadores;

class Ente
{
protected:
	int id;
	sf::Texture* textura;
	sf::RectangleShape corpo;
	GerenteGrafico* pGerenteGrafico;
public:
	Ente();
	virtual ~Ente();
	virtual void executar() = 0;
	virtual void imprimir() = 0 ;
	virtual void setTextura(const char* path);
	//virtual void update();
};


