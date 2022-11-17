#include "Menu.h"
#include <iostream>
#define WIDTH 1200
#define HEIGHT 720

void Menu::set_values()
{
	//pos = 0;
	//pressed = theselect = false;
	pos_mouse = { 0,0 };
	mouse_coord = { 0,0 };
}

Menu::Menu(): pos(0), pressed(false), theselect(false)
{
	setTextura("fundomenu1.png");
	corpo.setFillColor(sf::Color::Blue);
	corpo.setSize(sf::Vector2f(150.f, 150.f));
	set_values();
	std::cout << "constr menu" << std::endl;
}

Menu::~Menu()
{
}

void Menu::executar()
{
	imprimir();
}

void Menu::imprimir()
{
	pGerenteGrafico->clear();
	GerenteGrafico* pGerenteGraf = GerenteGrafico::getInstance();
	//std::cout << "imprime menu" << std::endl;
	pGerenteGrafico->render(&corpo);
}
