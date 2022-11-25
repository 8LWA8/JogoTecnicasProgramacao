#pragma once
#include "Estado.h"
#include <cstring>
#include <iostream>
#include <stdio.h>

using namespace Estados;

class TelaFinal :
    public Estado
{

    sf::Clock relogio;
    bool pressed;
    bool pedirNome;
    float pos;

    std::string nome;
    std::vector<std::string> textos;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<int> sizes;

    void loop_events();
public:
    TelaFinal();
    ~TelaFinal();

    void executar();
    void imprimir();
};

