#pragma once
//  Header.h
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 10/3/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#ifndef Base_includes_h
#define Base_includes_h

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <set>
#include <vector>

#include <SFML/Graphics.hpp>
// SFML usings
using sf::RenderWindow;
using sf::RenderTarget;
using sf::Clock;
using sf::Event;
using sf::RectangleShape;
using sf::Texture;
using sf::Sprite;
using sf::Vector2i;
using sf::Vector2f;
using sf::FloatRect;
using sf::View;
using sf::Clipboard;

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;
using std::pow;

using std::unique_ptr;
using std::move;

using std::list;
using std::set;

using std::map;
using std::make_pair;

using std::vector;

using std::runtime_error;

static const bool DEBUG_MODE = false;
#define LOCK_DT 1;


#endif /* Base_includes */