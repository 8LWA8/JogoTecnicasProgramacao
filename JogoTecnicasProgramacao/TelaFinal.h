#pragma once
#include "Estado.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;
using namespace Estados;

//C�digo do mapa inspirado em https://www.youtube.com/watch?v=aEgG4pidcKU

class TelaFinal :
    public Estado
{
    map<int, string> mapaRanking;
    sf::Clock relogio;
    bool pressed;
    bool pedirNome;
    float pos;
    int pontFinal;

    std::string nome;
    std::vector<std::string> textos;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<int> sizes;

    void loop_events();
public:
    TelaFinal();
    ~TelaFinal();

    void salvarRank();
    void recuperarRank();
    void setRank(int p);
    int getRank();
    void executar();
    void imprimir();
    map<int, string> getMapa();
};

