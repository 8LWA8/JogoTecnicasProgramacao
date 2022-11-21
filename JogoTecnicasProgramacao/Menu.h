#pragma once
#include "Ente.h"
#include "Estado.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace Estados;

//APAGAR//Código inspirado no vídeo: https://www.youtube.com/watch?v=h8-Q4eu3Qt4&t=148s e no Github: https://github.com/terroo/menu-sfml
class Menu :
    public Estado
{
    int pos;
    bool pressed, theselect;

    sf::Vector2i pos_mouse;
    sf::Vector2i mouse_coord;
    std::vector<const char*> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;

protected:
    void set_values();
    void loop_events(); //?
    void draw_all(); //?

public:
    Menu();
    ~Menu();
    void executar();
    void imprimir();
};

