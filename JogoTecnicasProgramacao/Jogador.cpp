#include "Jogador.h"
#include <iostream>
using namespace Entidades::Personagens;



Jogador::Jogador(): empoderado(false)
{
    this->setPontuacao(0);
    this->setNumVidas(1000.0f);
    this->setMov(true);
    corpo.setSize(sf::Vector2f(35.f, 70.f));
    corpo.setPosition(sf::Vector2f(0.f, 100.f));
    vel.setVal(2.0, 1.0);
    
}

Jogador::~Jogador()
{
}


void Jogador::executar()
{
    if (this->getVivo()) {
        this->imprimir();
        this->mover();
        this->resetColl();
        if (empoderado == true)
        {
            float dt = relogio.getElapsedTime().asSeconds();
            if (dt >= 3.0f)
            {
                empoderado = false;
                corpo.setFillColor(sf::Color::White);
                relogio.restart();
            }
        }

        if (corpo.getFillColor() == sf::Color::Red)
        {
            float dt = relogio.getElapsedTime().asSeconds();
            if (dt >= 1.0f)
            {
                corpo.setFillColor(sf::Color::White);
                relogio.restart();
            }
        }
    }
}




void Jogador::setPontuacao(int p)
{
    pontuacao = p;
}
int Jogador::getPontuacao()
{
    if (this != nullptr) {
        return pontuacao;
    }
    return 0;
}

void Jogador::ficarEmpoderado()
{
    relogio.restart();
    empoderado = true;
    corpo.setFillColor(sf::Color::Blue);
}

bool Jogador::getEmpoderado()
{
    return empoderado;
}




void Jogador::levarDano(float dano)
{
    if (this->empoderado == false) {
        this->num_vidas = this->num_vidas - dano;
        //std::cout << num_vidas << std::endl;
        corpo.setFillColor(sf::Color::Red);
    }
    if (this->num_vidas <= 0.0) 
    {
        Jogador::setVivo(false);
    }
}

void Jogador::salvar() 
{
    fstream Myfile;
    Myfile.open("assets//text.cvs", ios::out | ios::app);
    
    Myfile << this->getNumVidas() << "," << this->getPontuacao() << "," << this->getCoord()->getX() << "," << this->getCoord()->getY();
    Myfile.close();
}

void Jogador::recuperar() 
{
    fstream fin;


    fin.open("assets//text.cvs", ios::out);

    vector<string> row;
    string line, word, temp;


    while (fin >> temp){
    row.clear();

    // read an entire row and
    // store it in a string variable 'line'
    getline(fin, line);

        // used for breaking words


        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ',')) {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
    }
    
    int i = 0;

    for (i = 0; i < row.size(); i++)
    {
        if (i == 0) {
            std::cout << "Hier" << std::endl;
            std::cout << row[i] << std::endl;
            
        }
    }

}