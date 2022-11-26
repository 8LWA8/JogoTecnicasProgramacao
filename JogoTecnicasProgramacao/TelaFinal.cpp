#include "TelaFinal.h"

#define WIDTH 1200
#define HEIGHT 720
#define FONT_PATH "assets\\textures\\font.ttf"


using namespace Estados;

void TelaFinal::loop_events()
{

pGerenteGrafico->setText(nome);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && !pressed)
	{
		
		sf::String string = sf::Clipboard::getString();
		nome = std::string(string);
		nome = nome + " " + std::to_string(getRank());
		pressed = true;
		pGerenteGrafico->setText(nome);
		pGerenteGrafico->print(sf::Vector2f(-100.f, 200.f + pos), 30);
		pos += 10.0;
		salvarRank();
		recuperarRank();
	}

	float dt = relogio.getElapsedTime().asSeconds();
	if (dt >= 10.f)
	{
		pressed = false;
		
	}

}

TelaFinal::TelaFinal(): pressed(false), pedirNome(false), pos(0), pontFinal(0) 
{
	//Créditos da imagem: https://www.freepik.com/free-vector/realistic-stars-galaxy-background_14063401.htm#query=outer%20space%20background&position=43&from_view=keyword
	setTextura("fundo2.jpg");
	corpo.setPosition(sf::Vector2f(-600.f, -360.f));
	corpo.setSize(sf::Vector2f(WIDTH, HEIGHT));
	nome = "";
	textos = { "Fim de jogo", "teste", "Aperte K para copiar nome do clipboard"};
	//texts.resize(3);
	coords = { {-120,-250},{-300, -300},{-120, 280} };
	sizes = { 80,40,40 };
}

TelaFinal::~TelaFinal()
{
	
}

void TelaFinal::salvarRank() 
{
	std::ofstream ranking;

	ranking.open("salvar/ranking.txt", std::ios::app);
	

	if (!ranking.is_open())
	{
		std::cout << "ERRO ABRINDO ranking.txt" << std::endl;
		exit(1);
	}
	
	if (nome != "")
		ranking << nome << " ";
	
	//std::cout << " " << pontFinal << " " << std::endl;
	ranking << pontFinal << " " << std::endl;
	
	ranking.close();

}

void TelaFinal::recuperarRank() 
{
	std::ifstream ranking;
	std::string info;
	int pontuacaoFinal;

	ranking.open("salvar/ranking.txt", std::ios::out);
	
	
	
		/*if (getline(ranking, info)) {
			pGerenteGrafico->setText(info);
			pGerenteGrafico->print(sf::Vector2f(-100.f, 0.f + pos), 30);
			pos += 10.0;
		}*/
	
	

	while (!ranking.eof())
	{
		ranking >> info;
		ranking >> pontuacaoFinal;
		ranking >> pontuacaoFinal;
		//std::cout << info << " " << pontuacaoFinal << std::endl;
		mapaRanking.insert(pair<int, string>(pontuacaoFinal, info));
	}

	//for (auto pair : mapaRanking)
	//{
	//	//cout << pair.first << " - " << pair.second << std::endl;
	//}

}

void TelaFinal::setRank(int p) 
{
	this->pontFinal = p;

}

int TelaFinal::getRank() 
{
	return pontFinal;
}

void TelaFinal::executar()
{
	loop_events();
	imprimir();
	
}

void TelaFinal::imprimir()
{
	pGerenteGrafico->clear();
	//GerenteGrafico* pGerenteGraf = GerenteGrafico::getInstance();
	pGerenteGrafico->render(&corpo);

	//Imprime textos
	for (int i = 0; i < 3; i++) {
		if (i == 1) {
			pGerenteGrafico->setText(this->nome);
			pGerenteGrafico->print(sf::Vector2f(-100.f, 0.f), 30);
		}
		else {
			pGerenteGrafico->setText(textos[i]);
			pGerenteGrafico->setTextOutline(0);
			pGerenteGrafico->print(coords[i], sizes[i]);
		}
	}
}

map<int, string> TelaFinal::getMapa()
{
	return mapaRanking;
}
