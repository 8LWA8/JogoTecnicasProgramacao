#include "Fase.h"


using namespace Personagens;
using namespace Obstaculos;

namespace Fases{

	int Fase::num_jog = 2;

	void Fase::limpaTdsArq()
	{
		std::ofstream arquivo;

		arquivo.open("salvar/salvarJog.txt");
		if (!arquivo.is_open())
		{
			std::cout << "ERRO ABRINDO salvarJog.txt" << std::endl;
			exit(1);
		}
		arquivo.close();

		arquivo.open("salvar/salvarRobo.txt");
		if (!arquivo.is_open())
		{
			std::cout << "ERRO ABRINDO salvarRobo.txt" << std::endl;
			exit(1);
		}
		arquivo.close();

		arquivo.open("salvar/salvarRocha.txt");
		if (!arquivo.is_open())
		{
			std::cout << "ERRO ABRINDO salvarRocha.txt" << std::endl;
			exit(1);
		}
		arquivo.close();

		arquivo.open("salvar/salvarVilgax.txt");
		if (!arquivo.is_open())
		{
			std::cout << "ERRO ABRINDO salvarVilgax.txt" << std::endl;
			exit(1);
		}
		arquivo.close();

		arquivo.open("salvar/salvarEspi.txt");
		if (!arquivo.is_open())
		{
			std::cout << "ERRO ABRINDO salvarEspi.txt" << std::endl;
			exit(1);
		}
		arquivo.close();

		arquivo.open("salvar/salvarEsfera.txt");
		if (!arquivo.is_open())
		{
			std::cout << "ERRO ABRINDO salvarEsfera.txt" << std::endl;
			exit(1);
		}
		arquivo.close();
	}

	Fase::Fase() : jogador1(NULL), jogador2(NULL),  LEnt(), Ger(), pontTotal(0)
{
	this->setId(10);
	this->getCorpo()->setSize(sf::Vector2f(2100.0f, 1900.0f));
	this->getCorpo()->setPosition(sf::Vector2f(-700.0f, -500.0f));
	this->setTextura("assets//textures//background.jpg");

	criaRobos();
	criaRochas();
	criaPoderes();
	criaJogadores();
	/*
	Ger.incluirJogador(&jogador1);
	Ger.incluirJogador(&jogador2);
	Ger.incluirObstaculo(&chao);
	*/
}
	
	
	
Fase::~Fase()
{
	this->salvar();
	LEnt.limpaLista();
	Ger.getVecInimigos()->erase(Ger.getVecInimigos()->begin(), Ger.getVecInimigos()->end());
	
}


void Fase::criaRobos()
{
	//sorteia quantos inimigos (entre 3 e 5)

	int n = 3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		Robo* r1 = new Robo(sf::Vector2f(-600.f + 100.f*i, 100.f));
		Entidade* e1 = static_cast <Entidade*>(r1);
		LEnt.addEntidade(e1);
		Inimigo* i1 = static_cast <Inimigo*>(r1);
		Ger.getVecInimigos()->push_back(i1);
	}
}

void Fase::criaRochas()
{
	int n = 3 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		Rocha* r1 = new Rocha(sf::Vector2f(-600.f + 100.f * i, 0.f));
		Entidade* e1 = static_cast <Entidade*>(r1);
		LEnt.addEntidade(e1);
		Obstaculo* o1 = static_cast <Obstaculo*>(r1);
		Ger.getListObst()->push_back(o1);
	}
}

void Fase::criaPoderes()
{
	int n = 5 + rand() % 3;
	for (int i = 0; i < n; i++)
	{
		EsferaPoder* esfera = new EsferaPoder(sf::Vector2f(-550.f + 150.f * i, 150.f));
		Entidade* e1 = static_cast <Entidade*>(esfera);
		LEnt.addEntidade(e1);
		Ger.getVecPoder()->push_back(esfera);
	}
}

void Fase::criaJogadores() 
{
	if (jogador1 == NULL && num_jog == 1)
	{
		jogador1 = new Jogador1();
		LEnt.addEntidade(jogador1);
		Ger.getVecJogs()->push_back(jogador1);
	} else if (jogador1 == NULL && jogador2 == NULL) {
		jogador1 = new Jogador1();
		jogador2 = new Jogador2();
		LEnt.addEntidade(jogador1);
		LEnt.addEntidade(jogador2);
		Ger.getVecJogs()->push_back(jogador1);
		Ger.getVecJogs()->push_back(jogador2);
	}

}

Jogador1* Fase::getJog1() 
{
	if (jogador1 != NULL) 
	{
		return jogador1;
	}
	std::cout << "ERROR: ponteiro NULL" << std::endl;
	return NULL;
}
Jogador2* Fase::getJog2() {
	if (jogador2 != NULL)
	{
		return jogador2;
	}
	std::cout << "ERROR: ponteiro NULL" << std::endl;
	return NULL;
}

int Fase::getPontTotal() 
{
	
	if (this->jogador1 != NULL && this->jogador2 != NULL) 
	{
		this->setPontTotal(jogador1->getPontuacao() + jogador2->getPontuacao());
		return (jogador1->getPontuacao() + jogador2->getPontuacao());

	}
	else if (this->jogador2 == NULL) 
	{
		this->setPontTotal(jogador1->getPontuacao());
		return this->jogador1->getPontuacao();
	}
}

void Fase::setPontTotal(int p) 
{
	this->pontTotal = p;
}


void Fase::salvar() 
{/*
	std::string info = this->getJog1()->salvar();

	fstream file;
	file.open("file.csv", ios::out);

	if (file.fail()) 
	{
		cout << "Error file" << endl;
		return;
	}
	cout << "file" << endl;
	file << info << endl;
	file << info << endl;

	file.close();
	*/
	

}

void Fase::recuperar() 
{/*
	fstream file;
	file.open("file.csv", ios::out);

	if (file.fail()) {
		cout << "Error opening file" << endl;
		return;
	}
	string l;


	vector<string> row;
	string line, word, temp;
	stringstream s(l);

	int i = 0;
	while (getline(file, l, ',')) {

		row.push_back(l);
		cout << row[i] << endl;
		i++;
	}*/

	/*
	for (i = 0; i < row.size(); i++)
	{

			std::cout << row[i] << std::endl;
		
	}*/

	//file.clear();
}

bool Fase::venceuFase()
{
	vector <Inimigo*>::iterator it;
	for (it = Ger.getVecInimigos()->begin(); it != Ger.getVecInimigos()->end(); it++)
	{
		if ((*it)->getVivo())
		{
			return false;
		}
	}

	return true;
}

void Fase::setNumJog(int n)
{
	num_jog = n;
}

int Fase::getNumJog()
{
	return num_jog;
}

}

