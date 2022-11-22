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

	options = { "NomeJogo", "Fase 1", "Fase 2", "Ranking", "Sair" };
	texts.resize(5);
	//coords = { {0,-300},{0, -200},{0, -100},{0, 0},{0, 100} };
	sizes = { 20,24,24,20,24 };

	for (std::size_t i{}; i < texts.size(); ++i) {
	//	texts[i].setFont(FONT_PATH);
	//	texts[i].setString(options[i]);
		texts[i].setCharacterSize(sizes[i]);
		pGerenteGrafico->setText(options[i]);
		
	//	texts[i].setOutlineColor(sf::Color::Black);
	//	texts[i].setPosition(coords[i]);
		pGerenteGrafico->print(sf::Vector2f(0, 0));
	}
}

Menu::Menu(): pos(0), pressed(false), theselect(false)
{
	setTextura("fundomenu1.png");
	///corpo.setFillColor(sf::Color::Blue);
	corpo.setPosition(sf::Vector2f(-600.f, -360.f));
	corpo.setSize(sf::Vector2f(WIDTH, HEIGHT));
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
