#include "GerenteGrafico.h"

#include <cstring>
#include <iostream>

#define FONT_PATH "		" //<-- PEGAR UMA FONTE
#define WIDTH 1200
#define HEIGHT 720
#define FRAME_RATE 100

using namespace Gerenciadores;

	GerenteGrafico* GerenteGrafico::instance = NULL;


	GerenteGrafico::GerenteGrafico():

		window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "")),
		view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),
		texturesMap(),
		clock() 
	{
		font = NULL;
	}
	
		
	GerenteGrafico::~GerenteGrafico() 
	{
		std::map<const char*, sf::Texture*>::iterator it;
		for (it = texturesMap.begin(); it != texturesMap.end(); it++) 
		{
			delete(it->second);
		}
		delete(window);
	}

	GerenteGrafico* GerenteGrafico::getInstance() 
	{
		if (instance == NULL)
		{
			instance = new GerenteGrafico();
		}
		return instance;
	}

	float GerenteGrafico::dt = 0;

	void GerenteGrafico::deleteInstance() 
	{
		if (GerenteGrafico::instance != NULL) 
		{
			GerenteGrafico* pAux = GerenteGrafico::getInstance();
			delete pAux;
			pAux = NULL;
		}
	}
	

	void GerenteGrafico::render(sf::RectangleShape* body) 
	{
		window->draw(*body);
	}

	void GerenteGrafico::render(sf::Text* text) 
	{
		window->draw(*text);
	}

	void GerenteGrafico::display() 
	{
		if (isWindowOpen()) 
			window->display();
		
	}

	void GerenteGrafico::clear() 
	{
		if (isWindowOpen())
			window->clear();
	}

	bool GerenteGrafico::isWindowOpen() const 
	{
		return window->isOpen();
	}

	void GerenteGrafico::closeWindow() 
	{
		window->close();
	}
	void GerenteGrafico::handleWindowResize()
	{
		float aspectRatio = float(window->getSize().x / float(window->getSize().y));
		view.setSize(sf::Vector2f(HEIGHT * aspectRatio, HEIGHT));
		window->setView(view);
	}

	sf::Vector2u GerenteGrafico::getWindowSize() const 
	{
		return window->getSize();
	}

	void GerenteGrafico::CenterView(Coord* coord) 
	{
		view.setCenter(sf::Vector2f(coord->x, coord->y));
		window->setView(view);
	}

	sf::Texture* GerenteGrafico::loadTexture(const char* path) 
	{
		std::map<const char*, sf::Texture*>::iterator it = texturesMap.begin();

		while (it != texturesMap.end()) 
		{
			if (!strcmp(it->first, path))
				return it->second;
			it++;
		}

		sf::Texture* tex = new sf::Texture();

		if (!tex->loadFromFile(path)) 
		{
			std::cout << "ERRO CARREGANDO O ARQUIVO" << path << std::endl;
			exit(1);
		}
		texturesMap.insert(std::pair<const char*, sf::Texture*>(path, tex));
		return tex;
	}

	sf::RenderWindow* GerenteGrafico::getWindow() const 
	{
		return this->window;
	}

	sf::Font* GerenteGrafico::getFont()
	{
		if (!font) 
		{
			font = new sf::Font();
			if (!font->loadFromFile(FONT_PATH)) 
			{
				std::cout << "ERRO CARREGANDO A FONTE!" << std::endl;
				exit(1);
			}
		}
	return font;
	}

	void GerenteGrafico::updateDeltaTime() 
	{
		dt = clock.getElapsedTime().asSeconds();
		clock.restart();
	}

