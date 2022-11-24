#include "Menu.h"
#include <iostream>
#define WIDTH 1200
#define HEIGHT 720
#define N_BUTTONS 4
#define FONT_PATH "assets\\textures\\font.ttf"


void Menu::loop_events()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed)
	{
		pressed = true;
		botoes[optionSelected]->setFillColor(sf::Color::Blue);
		optionSelected++;
		if (optionSelected >= N_BUTTONS)
		{
			optionSelected = 0;
		}
		botoes[optionSelected]->setFillColor(sf::Color::Magenta);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed)
	{
		pressed = true;
		botoes[optionSelected]->setFillColor(sf::Color::Blue);
		optionSelected--;
		if (optionSelected < 0)
		{
			optionSelected = N_BUTTONS-1;
		}
		botoes[optionSelected]->setFillColor(sf::Color::Magenta);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !pressed)
	{
		Fases::Fase::setNumJog(1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && !pressed)
	{
		Fases::Fase::setNumJog(2);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !pressed)
	{
		//std::cout << optionSelected << std::endl;
		switch (optionSelected)
		{
		case 0:
			if (!Fases::Fase::getCarregar())
			{
				MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::jogar_fase1);
			}
			else
			{
				MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::carregar_fase1);
			}
			break;
		case 1:
			if(!Fases::Fase::getCarregar())
			{
				MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::jogar_fase2);
			}
			else
			{
				MaquinaEstados::getMaquinaEstados()->addEstado(IDs::IDs::carregar_fase2);
			}
			break;
		case 3:
			pGerenteGrafico->getWindow()->close();
			break;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !pressed)
	{
		Fases::Fase::setCarregar(true);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && !pressed)
	{
		Fases::Fase::setCarregar(false);
	}

	float dt = relogio.getElapsedTime().asSeconds();
	if (dt >= 0.5f)
	{
		pressed = false;
		relogio.restart();
	}
}

Menu::Menu() : pos(1), pressed(false), optionSelected(0)
{
	//Créditos da imagem: https://www.freepik.com/free-vector/realistic-stars-galaxy-background_14063401.htm#query=outer%20space%20background&position=43&from_view=keyword
	setTextura("fundo2.jpg");
	corpo.setPosition(sf::Vector2f(-600.f, -360.f));
	corpo.setSize(sf::Vector2f(WIDTH, HEIGHT));

	//Inicializa botões
	for (int i = 0; i < N_BUTTONS; i++)
	{
		sf::RectangleShape* botao = new sf::RectangleShape();
		botoes.push_back(botao);
		botoes[i]->setSize(sf::Vector2f(150.f, 40.f));
		botoes[i]->setPosition(-50, -150 + 100 * i);
		botoes[i]->setFillColor(sf::Color::Blue);
	}

	botoes[0]->setFillColor(sf::Color::Magenta);

	options = { "Exploradores Espaciais", "Fase 1", "Fase 2", "Ranking", "Sair" };
	texts.resize(5);
	coords = { {-150,-250},{-10, -150},{-10, -50},{-10, 50},{-10, 150} };
	sizes = { 45,30,30,30,30 };
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
	pGerenteGrafico->render(&corpo);

	//Imprime botões
	for (int i = 0; i < N_BUTTONS; i++)
	{
		pGerenteGrafico->render(botoes[i]);
	}

	//Imprime textos
	for (int i = 0; i < texts.size(); i++) {
		pGerenteGrafico->setText(options[i]);
		pGerenteGrafico->setTextOutline(0);
		pGerenteGrafico->print(coords[i], sizes[i]);
	}

	pGerenteGrafico->printJogSelec(Fases::Fase::getNumJog());
	pGerenteGrafico->printCarregaSelec(Fases::Fase::getCarregar());
}