#pragma once
#include "Ente.h"
#include "Estado.h"
#include "MaquinaEstados.h"
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
    bool pressed, theselect;

    sf::Clock relogio;

    sf::RectangleShape *bfase1;
    sf::RectangleShape *bfase2;
    sf::RectangleShape *branking;
    sf::RectangleShape *bsair;

    sf::Vector2i pos_mouse;
    sf::Vector2i mouse_coord;
    std::vector<std::string> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<int> sizes;

    void set_values();
    void loop_events();
    void moveUp();
    void moveDown();
    

public:
    Menu();
    ~Menu();
    void executar();
    void imprimir();
};

