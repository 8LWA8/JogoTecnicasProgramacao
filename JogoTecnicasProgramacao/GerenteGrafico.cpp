#include "GerenteGrafico.h"

#include <cstring>
#include <iostream>
#include <string>

#define FONT_PATH "assets\\textures\\font.ttf" //<-- PEGAR UMA FONTE
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
		fontFile.loadFromFile(FONT_PATH);
		tex.setFont(fontFile);
		tex.setString("");
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
		//std::cout << "grafico" << std::endl;
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
		//std::cout << "render" << std::endl;
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

	void GerenteGrafico::CenterView(float x, float y) 
	{
		view.setCenter(sf::Vector2f(x,y));
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
		try {
			if (tex->loadFromFile(path)) {
				texturesMap.insert(std::pair<const char*, sf::Texture*>(path, tex));
			}
				//exit(1);	
		}
		catch (std::exception const& e)
		{
			std::cout << "Erro cargando o arquivo" << std::endl;
		}
		
		
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

	void GerenteGrafico::print(sf::Vector2f pos, int tam)
	{
		/*sf::Text tex;
		tex.setString(text);*/
		std::string s = tex.getString();
		tex.setPosition(pos);
		tex.setCharacterSize(tam);
		tex.setOutlineColor(sf::Color::Red);
		//tex.setOutlineThickness(4);
		GerenteGrafico::render(&tex);
		//std::cout << "imprimiu texto" << std::endl;
	}

	void GerenteGrafico::printVidaJ1(float val) 
	{
		std::string str =  std::to_string(val);
		tex.setString("Vida astronauta 1 = "+str);
		
		
		tex.setPosition(sf::Vector2f(-590.0f, -350.0f));

		GerenteGrafico::render(&tex);
	}

	void GerenteGrafico::printVidaJ2(float val)
	{
		std::string str = std::to_string(val);
		tex.setString("Vida astronauta 2 = " + str);


		tex.setPosition(sf::Vector2f(-200.0f, -350.0f));

		GerenteGrafico::render(&tex);
	}

	void GerenteGrafico::printPont(int val)
	{
		std::string str = std::to_string(val);
		tex.setString("Pontuacao = " + str);
		tex.setFillColor(sf::Color::Yellow);
		tex.setPosition(sf::Vector2f(-590.0f, -290.0f));

		GerenteGrafico::render(&tex);
	}

	void Gerenciadores::GerenteGrafico::printJogSelec(int n)
	{
		std::string str = std::to_string(n);
		tex.setString("Numero de jogadores = " + str);

		tex.setFillColor(sf::Color::White);
		tex.setPosition(sf::Vector2f(-580.0f, -300.0f));
		GerenteGrafico::render(&tex);

		tex.setString("Pressione 1 ou 2 para");

		tex.setFillColor(sf::Color::White);
		tex.setPosition(sf::Vector2f(-580.0f, -240.0f));
		GerenteGrafico::render(&tex);

		tex.setString("mudar a quantidade");

		tex.setFillColor(sf::Color::White);
		tex.setPosition(sf::Vector2f(-580.0f, -210.0f));
		GerenteGrafico::render(&tex);
	}

	void Gerenciadores::GerenteGrafico::printNome(char letra)
	{

		tex.setString("" + letra);
	}

	void Gerenciadores::GerenteGrafico::printCarregaSelec(bool c)
	{

		std::string str;

		if (c == true)
		{
			str = "Recuperar jogo";
		}
		else
		{
			str = "Novo jogo";
		}
		

		tex.setString("Modo = " + str);

		tex.setFillColor(sf::Color::White);
		tex.setPosition(sf::Vector2f(-580.0f, 0.0f));
		GerenteGrafico::render(&tex);

		tex.setString("Pressione R para recuperar fase");

		tex.setFillColor(sf::Color::White);
		tex.setPosition(sf::Vector2f(-580.0f, 60.0f));
		GerenteGrafico::render(&tex);

		tex.setString("ou N para novo jogo");

		tex.setFillColor(sf::Color::White);
		tex.setPosition(sf::Vector2f(-580.0f, 90.0f));
		GerenteGrafico::render(&tex);
	}

	void Gerenciadores::GerenteGrafico::setText(std::string text)
	{
		tex.setString(text);
	}

	sf::Text Gerenciadores::GerenteGrafico::getText()
	{
		return tex;
	}

	void Gerenciadores::GerenteGrafico::setTextOutline(float value)
	{
		tex.setOutlineThickness(value);
		//std::cout << "menu outline" << tex.getOutlineThickness() << std::endl;
	}
