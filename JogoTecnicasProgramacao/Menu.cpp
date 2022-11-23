#include "Menu.h"
#include <iostream>
#define WIDTH 1200
#define HEIGHT 720
#define FONT_PATH "assets\\textures\\font.ttf"

void Menu::set_values()
{
	pos = 1;
	pressed = theselect = false;
	pos_mouse = { 0,0 };
	mouse_coord = { 0,0 };

	options = { "Exploradores Espaciais", "Fase 1", "Fase 2", "Ranking", "Sair" };
	texts.resize(5);
	coords = { {-150,-250},{-10, -150},{-10, -50},{-10, 50},{-10, 150} };
	sizes = { 45,30,30,30,30 };

	bfase1->setSize(sf::Vector2f(23, 26));
	bfase1->setPosition(0, 0);
	bfase1->setFillColor(sf::Color::Red);
}

void Menu::loop_events()
{
	//sf::Event event;
	//while (pGerenteGrafico->getWindow()->pollEvent(event))
	//{
	//	if (event.type == sf::Event::Closed)
	//	{
	//		pGerenteGrafico->getWindow()->close();
	//	}

	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	//	{
	//		if (pos < 4)
	//		{
	//			++pos;
	//			pressed = true;
	//			//texts[pos].setOutlineThickness(4);
	//			pGerenteGrafico->setText(options[pos]);
	//			//texts[pos - 1].setOutlineThickness(0);
	//			pGerenteGrafico->setTextOutline(4.0f);
	//			pGerenteGrafico->setText(options[pos-1]);
	//			//texts[pos - 1].setOutlineThickness(0);
	//			pGerenteGrafico->setTextOutline(0.0f);
	//			pressed = false;
	//			theselect = false;
	//			std::cout << pos << options[pos] << std::endl;
	//		}
	//	}
	//	//imprimir();
	//}
}

Menu::Menu() : pos(0), pressed(false), theselect(false)
{
	//Créditos da imagem: https://www.freepik.com/free-vector/realistic-stars-galaxy-background_14063401.htm#query=outer%20space%20background&position=43&from_view=keyword
	setTextura("fundo2.jpg");
	corpo.setPosition(sf::Vector2f(-600.f, -360.f));
	corpo.setSize(sf::Vector2f(WIDTH, HEIGHT));
	bfase1 = new sf::RectangleShape();
	/*bfase2 = new sf::RectangleShape();
	branking = new sf::RectangleShape();
	bsair = new sf::RectangleShape();*/
	set_values();
}

Menu::~Menu()
{
}

void Menu::executar()
{

	loop_events();
	imprimir();
}

void Menu::imprimir()
{
	pGerenteGrafico->clear();
	GerenteGrafico* pGerenteGraf = GerenteGrafico::getInstance();
	//std::cout << "imprime menu" << std::endl;
	pGerenteGrafico->render(&corpo);

	pGerenteGrafico->setText(options[0]);
	pGerenteGrafico->print(coords[0], 45);

	pGerenteGrafico->setText(options[1]);
	pGerenteGrafico->setTextOutline(4);
	pGerenteGrafico->print(coords[1], 30);

	for (int i = 2; i < texts.size(); i++) {
		if (!pressed)
		{
			pGerenteGrafico->setText(options[i]);
			pGerenteGrafico->setTextOutline(0);
			pGerenteGrafico->print(coords[i], 30);
		}
	}

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::jogar_fase1);
	}*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed)
	{
		pressed = true;
		if (pos < 4)
		{
			++pos;
			pressed = true;
			for (int i = 0; i < texts.size(); i++)
			{
				pGerenteGrafico->setText(options[i]);
				pGerenteGrafico->setTextOutline(0);
				pGerenteGrafico->print(coords[i], sizes[i]);
			}
			//texts[pos].setOutlineThickness(4);
			pGerenteGrafico->setText(options[pos]);
			pGerenteGrafico->setTextOutline(4);
			pGerenteGrafico->print(coords[pos], sizes[pos]);
			//texts[pos - 1].setOutlineThickness(0);
			
			std::cout << pos << options[pos] << std::endl;
		}

		/*if (optionSelected - 1 >= 0)
		{
			texts[optionSelected].setFillColor(sf::Color::White);
			optionSelected--;
			if (optionSelected == -1)
			{
				optionSelected = 2;
			}
			texts[optionSelected].setFillColor(sf::Color::Red);
		}*/

		
	}

	float dt = relogio.getElapsedTime().asSeconds();
	if (dt >= 0.5f)
	{
		pressed = false;
		//theselect = false;
		relogio.restart();
	}

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

	}*/
}