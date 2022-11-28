#include "TelaRanking.h"

#define WIDTH 1200
#define HEIGHT 720

TelaRanking::TelaRanking()
{
	//Créditos da imagem: https://www.freepik.com/free-vector/realistic-stars-galaxy-background_14063401.htm#query=outer%20space%20background&position=43&from_view=keyword
	setTextura("assets\\textures\\fundo2.jpg");
	corpo.setPosition(sf::Vector2f(-600.f, -360.f));
	corpo.setSize(sf::Vector2f(WIDTH, HEIGHT));

	recuperarRank();
}

TelaRanking::~TelaRanking()
{
}

void TelaRanking::recuperarRank()
{
	std::ifstream ranking;
	std::string info;
	int pontuacaoFinal;

	ranking.open("salvar/ranking.txt", std::ios::out);

	while (!ranking.eof())
	{
		ranking >> info;
		ranking >> pontuacaoFinal;
		ranking >> pontuacaoFinal;
		//std::cout << info << " " << pontuacaoFinal << std::endl;
		mapaRanking.insert(pair<int, string>(pontuacaoFinal, info));
	}

	for (auto pair : mapaRanking)
	{
		cout << pair.first << " - " << pair.second << std::endl;
	}

}

void TelaRanking::executar()
{
	imprimir();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		MaquinaEstados::getMaquinaEstados()->removerEstado();
	}
}

void TelaRanking::imprimir()
{
	pGerenteGrafico->clear();
	pGerenteGrafico->render(&corpo);
	pGerenteGrafico->setText("Pressione Esc para voltar.");
	pGerenteGrafico->print(sf::Vector2f(-200.f, -300.f), 40);
	int pos = 0;

	if (!mapaRanking.empty())
	{
		for (auto iter = mapaRanking.rbegin(); iter != mapaRanking.rend(); ++iter)
		{
			pos++;
			pGerenteGrafico->printRanking(iter->first, iter->second, 100.f * pos);
		}
	}
	else
	{
		pGerenteGrafico->setText("Sem Ranking");
		pGerenteGrafico->print(sf::Vector2f(-100.0f, 0.f), 50);
	}
}
