#include "TelaPause.h"

#define WIDTH 1200
#define HEIGHT 720

TelaPause::TelaPause()
{
	setTextura("assets\\textures\\fundo2.jpg");
	corpo.setPosition(sf::Vector2f(-600.f, -360.f));
	corpo.setSize(sf::Vector2f(WIDTH, HEIGHT));
}

TelaPause::~TelaPause()
{
}

void TelaPause::executar()
{
	imprimir();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		MaquinaEstados::getMaquinaEstados()->removerEstado();
	}
}

void TelaPause::imprimir()
{
	pGerenteGrafico->clear();
	pGerenteGrafico->render(&corpo);

	pGerenteGrafico->setText("Jogo Pausado. Pressione Esc para continuar.");
	pGerenteGrafico->print(sf::Vector2f(-250.f, 0.f), 40);
}
