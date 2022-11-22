#include "Menu.h"
#include <iostream>
#define WIDTH 1200
#define HEIGHT 720
#define FONT_PATH "assets\\textures\\font.ttf"

void Menu::set_values()
{
	//pos = 0;
	//pressed = theselect = false;
	pos_mouse = { 0,0 };
	mouse_coord = { 0,0 };

	options = { "Exploradores Espaciais", "Fase 1", "Fase 2", "Ranking", "Sair" };
	texts.resize(5);
	//coords = { {0,-300},{0, -200},{0, -100},{0, 0},{0, 100} };
	sizes = { 45,24,24,24,24 };

	
}

Menu::Menu(): pos(0), pressed(false), theselect(false)
{
	//Créditos da imagem: https://www.freepik.com/free-vector/realistic-stars-galaxy-background_14063401.htm#query=outer%20space%20background&position=43&from_view=keyword
	setTextura("fundo2.jpg");
	corpo.setPosition(sf::Vector2f(-600.f, -360.f));
	corpo.setSize(sf::Vector2f(WIDTH, HEIGHT));
	set_values();
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

	pGerenteGrafico->setText(options[0]);
	pGerenteGrafico->print(sf::Vector2f(-150.f, -250.f), 45);

	for (int i = 1; i < texts.size(); i++) {
		//texts[i].setCharacterSize(sizes[i]);
		pGerenteGrafico->setText(options[i]);
		pGerenteGrafico->print(sf::Vector2f(-10.f, -250.f + 100.f * i), 30);
	}
}
