#pragma once
#include "Ente.h"
#include "IDs.h"
#include "Estado.h"
#include "MaquinaEstados.h"
#include "Fase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
using namespace Estados;

//Código inspirado no vídeo: https://www.youtube.com/watch?v=h8-Q4eu3Qt4&t=148s e no Github: https://github.com/terroo/menu-sfml
class Menu :
    public Estado
{
    int pos;
    int optionSelected;
    bool pressed;

    sf::Clock relogio;


    std::vector<sf::RectangleShape*> botoes;

    std::vector<std::string> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<int> sizes;

    void loop_events();

public:
    Menu();
    ~Menu();
    void executar();
    void imprimir();
};

