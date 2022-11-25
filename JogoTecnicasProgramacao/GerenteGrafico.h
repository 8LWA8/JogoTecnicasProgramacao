//Baseado no codigo: https://youtu.be/RXmFcBGD8T8
#pragma once
#include <SFML/Graphics.hpp>
#include "Coord.h"
#include <string>
#include <map>


namespace Gerenciadores {
	class GerenteGrafico
	{
	private:
		sf::RenderWindow* window;
		sf::View  view;
		std::map<const char*, sf::Texture*> texturesMap;
		sf::Font* font;
		sf::Clock clock;
		sf::Text tex;
		sf::Font fontFile;
		static float dt;

		static Gerenciadores::GerenteGrafico* instance;
		

		GerenteGrafico(); 
	public:
		
		~GerenteGrafico();
		
		static GerenteGrafico* getInstance(); 
		static void deleteInstance();

		void render(sf::RectangleShape* body);
		void render(sf::Text* text);
		void display();
		void clear();
		bool isWindowOpen() const;
		void closeWindow();
		void handleWindowResize();
		void print(sf::Vector2f pos, int tam);
		void printVidaJ1(float val);
		void printVidaJ2(float val);
		void printPont(int val);
		void printJogSelec(int n);
		void printCarregaSelec(bool c);
		void setText(std::string text);
		
		sf::Text getText();
		void setTextOutline(float value);

		sf::RenderWindow* getWindow() const;
		sf::Vector2u getWindowSize() const;

		void CenterView(float x, float y);
		sf::Texture* loadTexture(const char* path);

		sf::Font* getFont();

		void updateDeltaTime();

	};

}