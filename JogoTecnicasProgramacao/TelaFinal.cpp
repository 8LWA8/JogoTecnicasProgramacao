#include "TelaFinal.h"

#define WIDTH 1200
#define HEIGHT 720
#define FONT_PATH "assets\\textures\\font.ttf"

using namespace Estados;

void TelaFinal::loop_events()
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !pressed)
	{
		pressed = true;
		pGerenteGrafico->getWindow()->close();
	}*/
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !pedirNome)
	{
		pedirNome = true;
		std::cin >> nome;
		std::cout << nome;
	}
}

TelaFinal::TelaFinal(): pressed(false), pedirNome(false)
{
	//Créditos da imagem: https://www.freepik.com/free-vector/realistic-stars-galaxy-background_14063401.htm#query=outer%20space%20background&position=43&from_view=keyword
	setTextura("fundo2.jpg");
	corpo.setPosition(sf::Vector2f(-600.f, -360.f));
	corpo.setSize(sf::Vector2f(WIDTH, HEIGHT));

	textos = { "Fim de jogo", "Pressione enter e digite seu nome", "Pressione esc para sair"};
	//texts.resize(3);
	coords = { {-120,-250},{-300, -300},{-120, 280} };
	sizes = { 80,40,40 };
}

TelaFinal::~TelaFinal()
{
	
}

void TelaFinal::executar()
{
	loop_events();
	imprimir();
}

void TelaFinal::imprimir()
{
	pGerenteGrafico->clear();
	GerenteGrafico* pGerenteGraf = GerenteGrafico::getInstance();
	pGerenteGrafico->render(&corpo);

	//Imprime textos
	for (int i = 0; i < 3; i++) {
		pGerenteGrafico->setText(textos[i]);
		pGerenteGrafico->setTextOutline(0);
		pGerenteGrafico->print(coords[i], sizes[i]);
	}
}
