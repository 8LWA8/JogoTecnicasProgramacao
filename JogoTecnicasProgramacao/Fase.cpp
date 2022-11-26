#include "Fase.h"


using namespace Personagens;
using namespace Obstaculos;

namespace Fases{

	int Fase::num_jog = 2;
	bool Fase::carregar = false;

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

		arquivo.open("salvar/salvarAlien.txt");
		if (!arquivo.is_open())
		{
			std::cout << "ERRO ABRINDO salvarAlien.txt" << std::endl;
			exit(1);
		}
		arquivo.close();


	}

	void Fase::mostrarTelaFim()
	{
		std::cout << "tela final" << std::endl;
		
	}

	Fase::Fase() : jogador1(NULL), jogador2(NULL),  LEnt(), Ger(), pontTotal(0)
	{
		this->getCorpo()->setSize(sf::Vector2f(2100.0f, 1900.0f));
		this->getCorpo()->setPosition(sf::Vector2f(-700.0f, -500.0f));
		this->setTextura("assets//textures//background.jpg");
		this->setId(10);

		if (carregar == false)
		{
			criaRobos();
			criaRochas();
			criaPoderes();
			criaJogadores();
		} else
		{
			float x;
			float y;
			bool estaVivo;

			ifstream dados;

			dados.open("salvar/salvarRobo.txt", ios::out);

			while (!dados.eof())
			{
				dados >> x;
				dados >> y;
				dados >> estaVivo;

				this->criaRobos(x, y, estaVivo);
			}

			dados.close();

			dados.open("salvar/salvarRocha.txt", ios::out);

			while (!dados.eof())
			{
				dados >> x;
				dados >> y;

				this->criaRochas(x, y);
			}

			dados.close();

			bool colec;

			dados.open("salvar/salvarEsfera.txt", ios::out);

			while (!dados.eof())
			{
				dados >> x;
				dados >> y;
				dados >> colec;

				this->criaPoderes(x, y, colec);
			}

			dados.close();

			bool empoder;
			int n_vidas;
			float pont;

			float x2;
			float y2;
			float empoder2;
			float n_vidas2;
			float pont2;
			float estaVivo2;


			dados.open("salvar/salvarJog.txt", ios::out);


			dados >> x;
			dados >> y;
			dados >> empoder;
			dados >> n_vidas;
			dados >> pont;
			dados >> estaVivo;

			if (num_jog == 2)
			{
				dados >> x2;
				dados >> y2;
				dados >> empoder2;
				dados >> n_vidas2;
				dados >> pont2;
				dados >> estaVivo2;
				this->criaJogadores(x, y, empoder, n_vidas, pont, estaVivo, x2, y2, empoder2, n_vidas2, pont2, estaVivo2);
			}
			else
			{
				this->criaJogadores(x, y, empoder, n_vidas, pont, estaVivo);
			}

			dados.close();
		}
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

void Fase::criaRobos(float x, float y, bool estaVivo)
{
	Robo* r1 = new Robo(sf::Vector2f(x, y));
	r1->setVivo(estaVivo);
	Entidade* e1 = static_cast <Entidade*>(r1);
	LEnt.addEntidade(e1);
	Inimigo* i1 = static_cast <Inimigo*>(r1);
	Ger.getVecInimigos()->push_back(i1);
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

void Fase::criaRochas(float x, float y)
{
	Rocha* r1 = new Rocha(sf::Vector2f(x, y));
	Entidade* e1 = static_cast <Entidade*>(r1);
	LEnt.addEntidade(e1);
	Obstaculo* o1 = static_cast <Obstaculo*>(r1);
	Ger.getListObst()->push_back(o1);
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

void Fase::criaPoderes(float x, float y, bool colec)
{
	EsferaPoder* esfera = new EsferaPoder(sf::Vector2f(x, y));
	esfera->setColetada(colec);
	Entidade* e1 = static_cast <Entidade*>(esfera);
	LEnt.addEntidade(e1);
	Ger.getVecPoder()->push_back(esfera);
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

void Fase::criaJogadores(float x, float y, bool empoder, float n_vidas, int pont, bool estaVivo)
{
	if (jogador1 == NULL && num_jog == 1)
	{
		jogador1 = new Jogador1(sf::Vector2f(x, y));
		if (empoder == true)
		{
			jogador1->ficarEmpoderado();
		}
		jogador1->setNumVidas(n_vidas);
		jogador1->setPontuacao(pont);
		jogador1->setVivo(estaVivo);
		LEnt.addEntidade(jogador1);
		Ger.getVecJogs()->push_back(jogador1);
	}
}

void Fase::criaJogadores(float x, float y, bool empoder, float n_vidas, int pont, bool estaVivo, float x2, float y2, bool empoder2, float n_vidas2, int pont2, bool estaVivo2)
{
	if (jogador1 == NULL && jogador2 == NULL)
	{
		jogador1 = new Jogador1(sf::Vector2f(x, y));
		if (empoder == true)
		{
			jogador1->ficarEmpoderado();
		}
		jogador1->setNumVidas(n_vidas);
		jogador1->setPontuacao(pont);
		jogador1->setVivo(estaVivo);
		LEnt.addEntidade(jogador1);
		Ger.getVecJogs()->push_back(jogador1);

		jogador2 = new Jogador2(sf::Vector2f(x, y));
		if (empoder == true)
		{
			jogador2->ficarEmpoderado();
		}
		jogador2->setNumVidas(n_vidas);
		jogador2->setPontuacao(pont);
		jogador2->setVivo(estaVivo);
		LEnt.addEntidade(jogador2);
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
	return -1;
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

bool Fase::getCarregar()
{
	return carregar;
}

void Fase::setCarregar(bool c)
{
	carregar = c;
}

void Fase::mostrarInfoFase()
{
	if (jogador1 != NULL && jogador2 != NULL) {
		this->pGerenteGrafico->printVidaJ1(jogador1->getNumVidas());
		this->pGerenteGrafico->printVidaJ2(jogador2->getNumVidas());
		pGerenteGrafico->printPont(this->getPontTotal());
	}
	else if (jogador1 != NULL) 
	{
		this->pGerenteGrafico->printVidaJ1(jogador1->getNumVidas());
		pGerenteGrafico->printPont(this->getPontTotal());
	}
}

}

